#include "Funciones.h"
#include "Lista.h"
#define     TEJIDO_PATH     "Tejido.txt"

enum imagenes{FONDO,NANOBOT,CELULA_S,CELULA_X,CELULA_Y,CELULA_Z,ANTICUERPO,DOSIS_A,DOSIS_B};


using namespace std;

int contador_vector(Nodo* vec[]){
    int i = 0;
    while(vec[i]!= NULL){
        i++;
    }
    return i;
}

bool apertura_archivo(ifstream &archivo){
    archivo.open(TEJIDO_PATH);
    if(archivo)
        return true;
    else
        return false;
}

void lectura_archivo(Lista* principal){
    string dato;
    ifstream archivo;                                                    //String para guardar que tipo de elemento estamos leyendo (celula,dosis,anticuerpo)
    int cant_datos = 1, cant_celulas = 0;

    //Lista* principal = new Lista();
    if(apertura_archivo(archivo)){
        cout<<"El archivo se abrio correctamente"<<endl;
        while(archivo>>dato){                                           //Voy guardando en dato las palabras y las analizo
            float pos_x,pos_y;
            char celula;
            if(dato == "celula"){                                       //Si es celula leo el tipo y le sumo uno al contador correspondiente
                archivo>>celula;
                archivo>>pos_x;
                archivo>>pos_y;
                if(celula == 'S'){

                    CelulaS* celula_s = new CelulaS(pos_x, pos_y,1, 0, 0, CELULA_S);
                    principal->alta(celula_s,cant_datos);
                }else if(celula == 'X'){

                    CelulaX* celula_x = new CelulaX(pos_x, pos_y, 1, 0, 20, CELULA_X);
                    principal->alta(celula_x,cant_datos);
                }else if(celula == 'Y'){

                    CelulaY* celula_y = new CelulaY(pos_x, pos_y, 1, 0, 40, CELULA_Y);
                    principal->alta(celula_y,cant_datos);
                }else if(celula == 'Z'){

                    CelulaZ* celula_z = new CelulaZ(pos_x, pos_y, 1, 0, 60, 100, CELULA_Z);
                    principal->alta(celula_z,cant_datos);
                }
                principal->llenar_vector(principal->obtener_nodo(cant_datos),cant_celulas);

                if(cant_celulas%2 == 0){
                    principal->alta_adyacente(principal->obtener_nodo_vector(cant_celulas), principal->obtener_nodo_vector(cant_celulas-1));    //C1 adyacente con C2
                    principal->alta_adyacente(principal->obtener_nodo_vector(cant_celulas-1), principal->obtener_nodo_vector(cant_celulas));    //C2 adyacente con C1
                }
                else if(cant_celulas%2 != 0 && cant_celulas != 1){
                    principal->alta_adyacente(principal->obtener_nodo_vector(cant_celulas-1), principal->obtener_nodo_vector(cant_celulas));    //C3 adyacente con C2
                    principal->alta_adyacente(principal->obtener_nodo_vector(cant_celulas-2), principal->obtener_nodo_vector(cant_celulas));    //C3 adyacente con C1
                    principal->alta_adyacente(principal->obtener_nodo_vector(cant_celulas), principal->obtener_nodo_vector(cant_celulas-2));    //C1 adyacente con C3
                    principal->alta_adyacente(principal->obtener_nodo_vector(cant_celulas), principal->obtener_nodo_vector(cant_celulas-1));    //C2 adyacente con C3 y asi sucesivamente
                }
                cant_celulas++;
                cant_datos++;
            }
            else if(dato == "dosis"){                                   //Si es una dosis leo el tipo de dosis y leo la cantidad de ese tipo en otra variable aux
                char tipo;
                int cantidad;
                archivo>>tipo;
                archivo>>cantidad;
                if(tipo == 'A'){
                    DosisA* dosis_a = new DosisA(cantidad, DosisA);
                    principal->alta(dosis_a,cant_datos);
                }else{
                    DosisB* dosis_b = new DosisB(cantidad, DosisB);
                    principal->alta(dosis_b,cant_datos);
                }
                cant_datos++;
            }
            else if(dato == "anticuerpo"){                              //Si es un anticuerpo sumo el contador de anticuerpos
                archivo>>pos_x;
                archivo>>pos_y;
                Anticuerpo* anticuerpo = new Anticuerpo(pos_x, pos_y, ANTICUERPO);
                principal->alta(anticuerpo,cant_datos);
                cant_datos++;
            }
        }
        archivo.close();
        principal->asignar_cantidad_celulas(cant_celulas);
    }
    else
        cout <<"-----------------------------------------\nNo se ha podido cargar el archivo correctamente"<< endl;
}

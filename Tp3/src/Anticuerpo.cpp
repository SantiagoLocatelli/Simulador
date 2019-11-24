#include "Anticuerpo.h"
#include "Constants.h"


const int NORTE = 0;
const int ESTE = 1;
const int SUR = 2;
const int OESTE = 3;
const int NOROESTE = 4;
const int NORESTE = 5;
const int SUROESTE = 6;
const int SURESTE = 7;
const int VELOCIDAD = 1;
const float LONGITUD_TEJIDO = 1000;
const float ALTO_TEJIDO = 600;
const float INICIO_TEJIDO = 0;

/*
Es una convencion tomada para el movimiento aleatorio del anticuerpo.
    0
3       1
    2
*/


Anticuerpo::Anticuerpo(float x,float y, int id):Organismos(x,y,id){

    asignar_tamanio(28,30);
}

Anticuerpo::Anticuerpo(){

    asignar_tamanio(28,30);
}

void Anticuerpo::mostrar(){

    cout<<"Anticuerpo:"<<endl;
    Organismos::mostrar();
}


void Anticuerpo::asignar_moverse(bool moverse){

    this->moverse = moverse;
}


bool Anticuerpo::obtener_moverse(){

    return moverse;
}


void Anticuerpo::mover(){

    float posicion_x = Organismos::get_posicion_x();
    float posicion_y = Organismos::get_posicion_y();

    char cont_up,cont_down,cont_left,cont_rigth = 0;


    int direccion = rand()%8; // esto devuelve un numero aleatorio entre 0 y 7

   // BRODAS le puse 5 nomas, porque me parecia que con 10 se iba a mover re loco mal, pero eso solo es cambiar a la velcidad y nada mas.
   if(moverse == 1){
        if( direccion == NORTE ){
            if( posicion_y-VELOCIDAD-ANTICUERPO_HEIGHT > INICIO_TEJIDO ){
                Organismos::set_posicion_y(posicion_y-VELOCIDAD);
            }
        }else if( direccion == ESTE ){
            if( posicion_x+VELOCIDAD+ANTICUERPO_WIDTH < LONGITUD_TEJIDO ){
                Organismos::set_posicion_x(posicion_x+VELOCIDAD);
            }
        }else if( direccion == SUR ){
            if( posicion_y+VELOCIDAD+ANTICUERPO_HEIGHT < ALTO_TEJIDO ){
                Organismos::set_posicion_y(posicion_y+VELOCIDAD);
            }
        }else if( direccion == OESTE){
            if( posicion_x-VELOCIDAD-ANTICUERPO_WIDTH > INICIO_TEJIDO ){// No se compara si la dirección es izquierda ya que por descarte debe ser si o si esta misma.
                Organismos::set_posicion_x(posicion_x-VELOCIDAD);
            }
        }else if( direccion == NORESTE ){
            if(posicion_x+VELOCIDAD+ANTICUERPO_WIDTH < LONGITUD_TEJIDO && posicion_y-VELOCIDAD-ANTICUERPO_HEIGHT > INICIO_TEJIDO){
                Organismos::set_posicion_x(posicion_x+VELOCIDAD);
                Organismos::set_posicion_y(posicion_y-VELOCIDAD);
            }
        }else if( direccion == NOROESTE ){
            if(posicion_x-VELOCIDAD-ANTICUERPO_WIDTH > INICIO_TEJIDO && posicion_y-VELOCIDAD-ANTICUERPO_HEIGHT > INICIO_TEJIDO){
                Organismos::set_posicion_y(posicion_y-VELOCIDAD);
                Organismos::set_posicion_x(posicion_x-VELOCIDAD);
            }
        }else if( direccion == SURESTE){
            if(posicion_y+VELOCIDAD+ANTICUERPO_HEIGHT < ALTO_TEJIDO && posicion_x+VELOCIDAD+ANTICUERPO_WIDTH < LONGITUD_TEJIDO){// No se compara si la dirección es izquierda ya que por descarte debe ser si o si esta misma.
                Organismos::set_posicion_y(posicion_y+VELOCIDAD);
                Organismos::set_posicion_x(posicion_x+VELOCIDAD);
            }
        }else if( direccion == SUROESTE){
            if( posicion_x-VELOCIDAD-ANTICUERPO_WIDTH > INICIO_TEJIDO && posicion_y+VELOCIDAD+ANTICUERPO_HEIGHT < ALTO_TEJIDO){// No se compara si la dirección es izquierda ya que por descarte debe ser si o si esta misma.
                Organismos::set_posicion_y(posicion_y+VELOCIDAD);
                Organismos::set_posicion_x(posicion_x-VELOCIDAD);
            }
        }

    }
}

Anticuerpo::~Anticuerpo(){
    //dtor
}

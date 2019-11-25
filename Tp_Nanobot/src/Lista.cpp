#include "Lista.h"


Lista::Lista(){
    primero = 0;
    cant_elementos=0;
    cant_celulas=0;
}

bool Lista::vacia(){

    return (primero == 0);
}


void Lista::alta(Elementos* dato, int pos){
    Nodo* nuevo = new Nodo(dato);

    if(pos == 1){
        nuevo->asignar_siguiente(primero);
        primero = nuevo;
    }
    else{
        Nodo* anterior = obtener_nodo(pos - 1);
        nuevo->asignar_siguiente(anterior->obtener_siguiente());
        anterior->asignar_siguiente(nuevo);
    }
    cant_elementos++;
}

void Lista::alta_adyacente(Nodo* vecino, Nodo* origen){
    Nodo* nuevo = new Nodo(vecino);

    //Nodo* anterior = obtener_nodo(posicion - 1);
    nuevo->asignar_siguiente_adyacente(origen->obtener_siguiente_adyacente());
    origen->asignar_siguiente_adyacente(nuevo);
}

void Lista::baja(int pos){
    Nodo* aux = primero;
    if(pos == 1){
        primero = aux->obtener_siguiente();
    }
    else{
        Nodo* anterior = obtener_nodo(pos - 1);
        aux = anterior->obtener_siguiente();
        anterior->asignar_siguiente(aux->obtener_siguiente());
    }
    delete aux;
    cant_elementos--;
}

Nodo* Lista::obtener_nodo(int pos){
    Nodo* aux = primero;
    for(int i = 1; i< pos; i++){
        aux = aux->obtener_siguiente();
    }
    return aux;
}

Nodo* Lista::obtener_nodo_vector(int pos){
    return vec_nodos[pos];
}

void Lista::llenar_vector(Nodo* nodo, int pos){
    vec_nodos[pos] = nodo;
}

void Lista::asignar_cantidad_celulas(int cant_celulas){
    this->cant_celulas=cant_celulas;
}

int Lista::obtener_tamanio(){
    return cant_elementos;
}


int Lista::obtener_cantidad_celulas(){
   return cant_celulas;
}

/*void Lista::mostrar_lista(){
    int i = 1;
    Nodo* actual = primero;
    while(actual){
        Nodo aux = obtener_nodo(i);
        cout<< &aux<<endl;
        actual->obtener_siguiente();
        i++;
    }
}*/

Lista::~Lista()
{
    while( !vacia() ){
      baja(1);
    }
}

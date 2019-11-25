#include "Nodo.h"

Nodo::Nodo(){
    dato = 0;
    siguiente = 0;
    siguiente_adyacente = 0;
}

Nodo::Nodo(Elementos* dato){
    asignar_dato(dato);
    siguiente = 0;
    siguiente_adyacente = 0;
}

Nodo::Nodo(Nodo* nodo){
    asignar_siguiente_adyacente(nodo);
    siguiente = 0;
    siguiente_adyacente = 0;
}

void Nodo::asignar_dato(Elementos* dato){

    this->dato = dato;
}

void Nodo::asignar_siguiente(Nodo* siguiente){

    this->siguiente = siguiente;
}

void Nodo::asignar_siguiente_adyacente(Nodo* siguiente_adyacente){

    this->siguiente_adyacente = siguiente_adyacente;
}

Nodo* Nodo::obtener_siguiente(){
    return siguiente;
}

Nodo* Nodo::obtener_siguiente_adyacente(){
    return siguiente_adyacente;
}

Elementos* Nodo::obtener_dato(){

    return dato;
}


Nodo::~Nodo(){
    //dtor
}

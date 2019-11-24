#include "Dosis.h"

Dosis::Dosis(int cantidad, id_elementos id):Elementos(id){

    this->cantidad = cantidad;
}

void Dosis::asignar_cantidad(int cantidad){

    this->cantidad = cantidad;
}

int Dosis::obtener_cantidad(){

    return cantidad;
}

void Dosis::mostrar(){

    cout<<"Tiene "<<cantidad<<" dosis"<<endl;
}

Dosis::~Dosis(){
    //dtor
}

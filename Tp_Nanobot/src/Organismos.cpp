#include "Organismos.h"

Organismos::Organismos(float x,float y, id_elementos id):Elementos(id){

    posicion[0] = x;
    posicion[1] = y;
}
Organismos::Organismos(){

}
void Organismos ::asignar_tamanio(int tamanio_x,int tamanio_y){

    tamanio[0] = tamanio_x;
    tamanio[1] = tamanio_y;
}
void Organismos ::mostrar(){

    cout<<"Su tamanio corresponde a:"<<tamanio[0]<<"x,"<<tamanio[1]<<"y"<<endl;
    cout<<"Su posicion corresponde a:"<<posicion[0]<<"x,"<<posicion[1]<<"y"<<endl;
}

int Organismos::get_tamanio_x(){
    return tamanio[0];
}

int Organismos::get_tamanio_y(){
    return tamanio[1];
}

void Organismos::set_posicion_x(float pos_x){
    posicion[0] = pos_x;
}

void Organismos::set_posicion_y(float pos_y){
    posicion[1] = pos_y;
}

int Organismos::get_posicion_x(){
    return posicion[0];
}

int Organismos::get_posicion_y(){
    return posicion[1];
}

Organismos::~Organismos(){
    //dtor
}

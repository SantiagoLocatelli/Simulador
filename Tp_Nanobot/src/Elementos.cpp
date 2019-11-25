#include "Elementos.h"

Elementos::Elementos(){

  id = NADA;
}

Elementos::Elementos( id_elementos id ){

  this->id = id;
}

void Elementos::establecer_id( id_elementos id ){

  this->id = id;
}

id_elementos Elementos::obtener_id(){

  return id;
}

void Elementos::mostrar(){

}

int Elementos::get_posicion_x(){

}
int Elementos::get_posicion_y(){

}


Elementos::~Elementos()
{
    //dtor
}

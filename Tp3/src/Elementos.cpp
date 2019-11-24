#include "Elementos.h"

Elementos::Elementos(){

  id_elemento = 0;
}

Elementos::Elementos( int id ){

  id_elemento = id;
}

void Elementos::establecer_id( int id ){

  id_elemento = id;
}

int Elementos::obtener_id(){

  return id_elemento;
}

void Elementos::mostrar(){

}

Elementos::~Elementos()
{
    //dtor
}

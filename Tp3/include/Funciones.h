#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include "CelulaX.h"
#include "CelulaY.h"
#include "CelulaS.h"
#include "CelulaZ.h"
#include "Anticuerpo.h"
#include "DosisA.h"
#include "DosisB.h"
#include "Lista.h"

#include <iostream>
#include <fstream>



void lectura_archivo(Lista* principal);     //Funcino dedicada a la lectura y el guardado de datos del archivo

// PRE: Recibe por referencia el archivo.
// POS: Abrira el archivo y en caso de que se abra bien devuelte true, sino false.
bool apertura_archivo(ifstream &archivo);                                                                        //Funcion dedicada a ver si existe el archivo y ver si se puede realizar la lectura

// PRE: Debe recibir un vector de punteros de Objetos Elemento y un puntero a un int que almacena el maximo logico del vector.
// POS: Procesara el archivo provisto.

int obtener_posicion_x(Lista* lista,int i);

int obtener_posicion_y(Lista* lista,int i);
#endif // FUNCIONES_H_INCLUDED

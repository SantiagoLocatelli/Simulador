#ifndef NODO_H
#define NODO_H


#include "Elementos.h"

class Nodo{

public:
    Nodo();

    Nodo(Elementos* dato);

    Nodo(Nodo* nodo);

    // PRE: El puntero a nodo debe apuntar a un nodo inicializado.
    // POS: El nodo pasado pasara a ser el siguiente de este nodo.
    void asignar_siguiente(Nodo* siguiente);

    // PRE: El elemento debera estar inicializado.
    // POS: El elemento pasado pasara a estar almacenada en el nodo.
    void asignar_dato(Elementos* dato);

    void asignar_siguiente_adyacente(Nodo* siguiente_adyacente);

    // PRE: --------------------------------------.
    // POS: Devolvera el elemento almacenado en el nodo.
    Elementos* obtener_dato();

    // PRE: --------------------------------------.
    // POS: Devolvera el nodo siguiente del nodo alctual.
    Nodo* obtener_siguiente();

    Nodo* obtener_siguiente_adyacente();

    virtual ~Nodo();

private:

    Nodo* siguiente;
    Nodo* siguiente_adyacente;
    Elementos* dato;
};

#endif // NODO_H

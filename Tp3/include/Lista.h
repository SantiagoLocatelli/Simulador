#ifndef LISTA_H
#define LISTA_H


const int MAX = 1000;

#include "Nodo.h"

class Lista{

    public:

        Lista();

        // PRE: La posicion debera estar entre 1 y el tamanio de las lista y elemento debe estar inicializado.
        // POS: Dara de alta el elemento en la posicion pasada.
        void alta(Elementos* dato, int pos);

        // PRE: La posicion debera estar entre 1 y el tamanio de las lista.
        // POS: Dara de baja el elemento de la lista en la posicion pasada.
        void baja(int pos);

        // PRE:---------------------------------.
        // POS: Devolvera el tamanio de la lista.
        int obtener_tamanio();

        // PRE: La posicion debera estar entre 1 y el tamanio de las lista.
        // POS: Devolvera el nodo en la poscion pasada.
        Nodo* obtener_nodo(int pos);

        bool vacia();

        void mostrar_lista();

        virtual ~Lista();

        //Funciones de segunda lista
        void asignar_cantidad_celulas(int cant_celulas);

        int obtener_cantidad_celulas();

        void alta_adyacente(Nodo* vecino, Nodo* origen);

        void llenar_vector(Nodo* nodo, int pos);

        Nodo* obtener_nodo_vector(int pos);

    private:
        Nodo* primero;
        Nodo* ultimo;
        int cant_elementos;
        int cant_celulas;
        Nodo* vec_nodos[MAX];       //Vector que almacena los punteros de los nodos que contienen celulas
};

#endif // LISTA_H

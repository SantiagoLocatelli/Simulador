#ifndef ORGANISMOS_H
#define ORGANISMOS_H

#include "Elementos.h"

enum Cordenadas{x,y};

class Organismos : public Elementos{
    public:

        // PRE: Debe recibir una coordenada válida.
        // POS: Inicializará la posición del objeto.
        Organismos(float posicion_x, float poscion_y, id_elementos id);

        Organismos();

        virtual ~Organismos();

        // PRE: Deben ser dos valores positivos.
        // POS: Asignará el tamanio del elemento con los valores pasados.
        void asignar_tamanio(int tamanio_x, int tamanio_y);

        // PRE: ----------------------------.
        // POS: Devolverá el tamaño del elemento con respecto al eje x.
        int get_tamanio_x();

        // PRE: ----------------------------.
        // POS: Devolverá el tamaño del elemento con respecto al eje y.
        int get_tamanio_y();

        // PRE: Lo posición pasada debe estar entre los valores propuesto por el enunciado.
        // POS: La posición pasada pasará a ser la nueva posición con respecto al eje x.
        void set_posicion_x(float pos_x);

        // PRE: Lo posición pasada debe estar entre los valores propuesto por el enunciado.
        // POS: La posición pasada pasará a ser la nueva posición con respecto al eje y.
        void set_posicion_y(float pos_y);

        // PRE: ----------------------------.
        // POS: Devolverá la posición del elemento con respecto al eje x.
        int get_posicion_x();

        // PRE: ----------------------------.
        // POS: Devolverá la posición del elemento con respecto al eje y.
        int get_posicion_y();

        // PRE: --------------------------------.
        // POS: Mostrara por pantalla los atributos del elemento.
        virtual void mostrar();

    private:

        float posicion[2];
        int tamanio[2];
};

#endif // ORGANISMOS_H

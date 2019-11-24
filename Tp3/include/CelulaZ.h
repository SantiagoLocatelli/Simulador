#ifndef CELULAZ_H
#define CELULAZ_H

#include "Celula.h"

class CelulaZ: public Celula{

    public:

        // PRE: La coordenada debera estar dentro de la matriz, la inflamacion entre 0 y 100 (vale decimales).
        // POS: Inicializara un objeto celula con los parametros pasados.
        CelulaZ(float x, float y, bool adn, bool unicelular, float _mutacion, float inflamacion, id_elementos id);

        virtual ~CelulaZ();

        // PRE: La mutacion debe ser un valor entre el 1 y el 100.
        // POS: El valor pasado por parametro pasara a ser la nueva mutacion.
        void establecer_mutacion( float mutacion );

        // PRE: -----------------------------.
        // POS: Devolvera la mutacion del objeto.
        float obtener_mutacion();

        // PRE: --------------------------------.
        // POS: Mostrara por pantalla los atributos del objeto.
        void mostrar();

    private:

        float mutacion;
};

#endif // CELULAZ_H

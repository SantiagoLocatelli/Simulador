#ifndef DOSIS_H
#define DOSIS_H

#include "Elementos.h"

class Dosis : public Elementos{

    public:

        // PRE: El entero recibido debe ser un valor valido.
        // POS: Inicilizara el objeto dosis con una cantidad de dosis pasada por parametro.
        Dosis(int cantidad, id_elementos id);

        // PRE: El entero recibido debe ser un valor valido, es decir, positivo.
        // POS: Asignara el valor pasado a la cantidad.
        void asignar_cantidad(int cantidad);

        // PRE: --------------------------------.
        // POS: Devolvera la cantidad de dosis del objeto.
        int obtener_cantidad();

        // PRE: --------------------------------.
        // POS: Mostrara por pantalla los atributos del elemento.
        virtual void mostrar();

        virtual ~Dosis();

    private:

        int cantidad;
};

#endif // DOSIS_H

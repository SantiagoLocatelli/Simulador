#ifndef DOSISA_H
#define DOSISA_H
#include "Dosis.h"

class DosisA: public Dosis
{
    public:

        // PRE: El entero recibido debe ser un valor valido.
        // POS: Inicilizara el objeto dosis con una cantidad de dosis pasada por parametro.
        DosisA(int cantidad, id_elementos id);

        virtual ~DosisA();

        // PRE: --------------------------------.
        // POS: Mostrara por pantalla los atributos del elemento.
        void mostrar();

        void eliminar();

    private:
};

#endif // DOSISA_H

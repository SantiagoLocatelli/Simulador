#ifndef DOSISB_H
#define DOSISB_H

#include "Dosis.h"

class DosisB : public Dosis{

    public:

        // PRE: El entero recibido debe ser un valor valido.
        // POS: Inicilizara el objeto dosis con una cantidad de dosis pasada por parametro.
        DosisB(int cantidad, id_elementos id);

        virtual ~DosisB();

        // PRE: --------------------------------.
        // POS: Mostrara por pantalla los atributos del elemento.
        void mostrar();

        void duplicar();

    private:
};

#endif // DOSISB_H

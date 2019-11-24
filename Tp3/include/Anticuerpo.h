#ifndef ANTICUERPO_H
#define ANTICUERPO_H

#include "Organismos.h"

#include <time.h>
#include <stdlib.h>

class Anticuerpo: public Organismos{
    public:

        // PRE: Debe recibir una coordenada que este dentro de la matriz.
        // POS: Iniciliazara la posicion del objeto.
        Anticuerpo(float x, float , int id);
        Anticuerpo();

        virtual ~Anticuerpo();

        // PRE: --------------------------------.
        // POS: Mostrara por pantalla los atributos del elemento.
        void mostrar();

        // PRE: ------------------------------------.
        // POS: Moverá el anticuerpo aleatoriamente por todo el tejido.
        void mover();

        void asignar_moverse(bool moverse);

        bool obtener_moverse();

    private:

        bool moverse;

};

#endif // ANTICUERPO_H

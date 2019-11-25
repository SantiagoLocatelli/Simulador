#ifndef CELULAS_H
#define CELULAS_H

#include "Celula.h"

class CelulaS: public Celula{

    public:

        // PRE: La coordenada debera estar dentro de la matriz, la inflamacion entre 0 y 100 (vale decimales).
        // POS: Inicializara un objeto celula con los parametros pasados.
        CelulaS(float x, float y, bool adn, bool unicelular, float inflamacion, id_elementos id);

        virtual ~CelulaS();

        // PRE: --------------------------------.
        // POS: Mostrara por pantalla los atributos del objeto.
        void mostrar();

    private:
};

#endif // CELULAS_H

#ifndef CELULAXY_H
#define CELULAXY_H

#include "Celula.h"

class CelulaX: public Celula{

    public:

        // PRE: La coordenada debera estar dentro de la matriz, la inflamacion entre 0 y 100 (vale decimales).
        // POS: Inicializara un objeto celula con los parametros pasados.
        CelulaX(float x, float y, bool adn, bool unicelular, float inflamacion, id_elementos id);

        virtual ~CelulaX();

        // PRE: --------------------------------.
        // POS: Mostrara por pantalla los atributos del objeto.
        void mostrar();

    private:

};

#endif // CELULAXY_H

#ifndef CELULAY_H
#define CELULAY_H

#include "Celula.h"

class CelulaY : public Celula{

    public:

        // PRE: La coordenada debera estar dentro de la matriz, la inflamacion entre 0 y 100 (vale decimales).
        // POS: Inicializara un objeto celula con los parametros pasados.
        CelulaY(float x, float y, bool adn, bool unicelular, float inflamacion, id_elementos id);

        virtual ~CelulaY();

        // PRE: --------------------------------.
        // POS: Mostrara por pantalla los atributos del objeto.
        void mostrar();

    private:

};


#endif // CELULAY_H

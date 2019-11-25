#ifndef TP1_H_INCLUDED
#define TP1_H_INCLUDED
#include <iostream>

using namespace std;

// Empieza en 2 para que coincida con el enumerado imagenes de entorno.
enum id_elementos{CEL_S = 2,CEL_X,CEL_Y,CEL_Z,ANTI_CUERPO,DOSI_A,DOSI_B,NADA};

class Elementos{

    private:

      id_elementos id;

    public:

        // PRE: --------------------------------.
        // POS: --------------------------------.
        Elementos();

        Elementos( id_elementos id );

        id_elementos obtener_id();

        void establecer_id(id_elementos id);

        // PRE: --------------------------------.
        // POS: Mostrara por pantalla los atributos del elemento.
        virtual void mostrar();
        virtual int get_posicion_x();
        virtual int get_posicion_y();
        virtual ~Elementos();
};

#endif // TP1_H_INCLUDED

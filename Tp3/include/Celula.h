#ifndef CELULAS_H_INCLUDED
#define CELULAS_H_INCLUDED

#include "Organismos.h"

class Celula: public Organismos{

    private:

        int cant_proteinas;
        int cant_enzimas;
        bool adn;
        bool unicelular;
        float inflamacion;

    public:

        // PRE: La coordenada debera estar dentro de la matriz, la inflamacion entre 0 y 100 (vale decimales).
        // POS: Inicializara un objeto celula con los parametros pasados.
        Celula(float x, float y, bool _adn, bool _unicelular, float _inflamacion, id_elementos id);

        virtual ~Celula();

        // PRE: --------------------------------.
        // POS: Mostrara por pantalla los atributos del objeto.
        virtual void mostrar();

        // PRE: --------------------------------.
        // POS: Devolvera la inflamacion del objeto.
        float obtener_inflamacion();

        // PRE: El parametro pasado debe ser un numero entre 0 y 100.
        // POS: El parametro pasara a ser la inflamacion del objeto.
        void establecer_inflamacion(float inflamacion);

};

#endif // CELULAS_H_INCLUDED

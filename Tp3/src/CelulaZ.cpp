#include "CelulaZ.h"

CelulaZ::CelulaZ(float x, float y, bool adn, bool unicelular, float _mutacion, float inflamacion, id_elementos id):Celula(x, y, adn, unicelular, inflamacion, id){

    mutacion = _mutacion;
}

void CelulaZ::establecer_mutacion( float mutacion ){

    this->mutacion = mutacion;
}

float CelulaZ::obtener_mutacion(){

    return mutacion;
}

void CelulaZ::mostrar(){

    cout<<"Celula tipo Z"<<endl;
    cout<< "Porcentaje de Mutación:%"<<mutacion<<endl;
    Celula::mostrar();
}

CelulaZ::~CelulaZ(){
    //dtor
}

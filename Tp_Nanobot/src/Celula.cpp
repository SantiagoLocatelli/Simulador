#include "Celula.h"

Celula::Celula(float x, float y, bool _adn, bool _unicelular, float _inflamacion, id_elementos id):Organismos(x,y, id){

    adn = _adn;
    unicelular = _unicelular;
    inflamacion = _inflamacion;
    asignar_tamanio(60,60);
}

Celula::~Celula(){

}

void Celula::establecer_inflamacion(float inflamacion){

    this->inflamacion = inflamacion;
}

void Celula::mostrar(){

    Organismos::mostrar();
    cout<<"Cantidad de proteinas:"<<cant_proteinas<<endl;
    cout<<"Cantidad de enzimas:"<<cant_enzimas<<endl;

    if(adn) cout<<"Tiene adn"<<endl;
    else cout<<"Tiene arn"<<endl;
    if(unicelular)  cout<<"Es unicelular"<<endl;
    else cout<<"Es pluricelular"<<endl;

    cout<<"Porcentaje de inflamacion: %"<<inflamacion<<endl;

}
float Celula::obtener_inflamacion(){

    return (inflamacion);
}

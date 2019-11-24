#include "CelulaX.h"

CelulaX::CelulaX(float x,float y,bool adn,bool unicelular,float inflamacion):Celula(x,y,adn,unicelular,inflamacion)
{}
void CelulaX::mostrar(){
    cout<<"Celula tipo X"<<endl;
    Celula::mostrar();
}
CelulaX::~CelulaX()
{
    //dtor
}

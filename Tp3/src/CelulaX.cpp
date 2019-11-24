#include "CelulaX.h"

CelulaX::CelulaX(float x,float y,bool adn,bool unicelular,float inflamacion, int id):Celula(x,y,adn,unicelular,inflamacion, id)
{}
void CelulaX::mostrar(){
    cout<<"Celula tipo X"<<endl;
    Celula::mostrar();
}
CelulaX::~CelulaX()
{
    //dtor
}

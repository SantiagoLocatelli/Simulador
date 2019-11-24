#include "CelulaS.h"

CelulaS::CelulaS(float x, float y, bool adn, bool unicelular, float inflamacion):Celula(x,y,adn,unicelular,inflamacion){

}

void CelulaS::mostrar(){

    cout<<"Celula tipo S"<<endl;
    Celula::mostrar();
}

CelulaS::~CelulaS(){
    //dtor
}

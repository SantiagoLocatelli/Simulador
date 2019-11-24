#include "CelulaS.h"

CelulaS::CelulaS(float x, float y, bool adn, bool unicelular, float inflamacion, id_elementos id):Celula(x,y,adn,unicelular,inflamacion, id){

}

void CelulaS::mostrar(){

    cout<<"Celula tipo S"<<endl;
    Celula::mostrar();
}

CelulaS::~CelulaS(){
    //dtor
}

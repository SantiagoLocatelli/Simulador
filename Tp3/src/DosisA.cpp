#include "DosisA.h"

DosisA::DosisA(int cantidad):Dosis(cantidad){

}

void DosisA::mostrar(){

    cout<<"Dosis tipo A"<<endl;
    Dosis::mostrar();
}

DosisA::~DosisA(){
    //dtor
}

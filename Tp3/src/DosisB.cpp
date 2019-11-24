#include "DosisB.h"

DosisB::DosisB(int cantidad):Dosis(cantidad){
    //ctor
}

void DosisB::mostrar(){

    cout<<"Dosis tipo B"<<endl;
    Dosis::mostrar();
}

DosisB::~DosisB()
{
    //dtor
}

#include "DosisB.h"

DosisB::DosisB(int cantidad, int id):Dosis(cantidad, id){
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

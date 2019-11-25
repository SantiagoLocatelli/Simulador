#include "DosisB.h"

DosisB::DosisB(int cantidad, id_elementos id):Dosis(cantidad, id){
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

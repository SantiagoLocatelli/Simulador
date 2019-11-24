#include "DosisA.h"

DosisA::DosisA(int cantidad, int id):Dosis(cantidad, id){

}

void DosisA::mostrar(){

    cout<<"Dosis tipo A"<<endl;
    Dosis::mostrar();
}

DosisA::~DosisA(){
    //dtor
}

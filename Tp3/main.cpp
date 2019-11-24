#include <iostream>
#include "Juego.h"
#include "Nanobot.h"
using namespace std;


Juego* juego = 0;

int main() {
    srand ((unsigned) time(NULL));
    juego = new Juego();
    juego->iniciar("Nanobot", 100, 100, 0);
    juego->correr();
    juego->limpiar();

    delete juego;
    return 0;
}

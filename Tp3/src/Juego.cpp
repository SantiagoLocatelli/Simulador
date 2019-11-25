//
// Created by caropistillo
//
#include "Juego.h"
#include "Constants.h"

using namespace std;

const int SCREEN_FPS = 30;


void Juego::iniciar(const char *title, int xpos, int ypos, int flags){

    entorno.iniciar(title,xpos,ypos,flags);
}


Juego::Juego(){

	running = false;
	nanobot.asignar_x(POS_NANOBOT_X);
	nanobot.asignar_y(POS_NANOBOT_Y);
	lista = new Lista();
  lectura_archivo(lista);
}



bool Juego::intersececion_n(Nanobot nanobot,Anticuerpo anticuerpo){

    if(anticuerpo.get_posicion_x()>nanobot.get_x()-NANOBOT_WIDTH && anticuerpo.get_posicion_x()<nanobot.get_x()+NANOBOT_WIDTH){
        if(anticuerpo.get_posicion_y()>nanobot.get_y()-NANOBOT_HEIGHT && anticuerpo.get_posicion_y()<nanobot.get_y()+NANOBOT_HEIGHT){
            return 1;
        }
    }
    return 0;
}



void Juego::correr() {

	running = true;
	FPSManager fpsManager(SCREEN_FPS);

	while(running) {
		fpsManager.start();
		//manejarEventos();
		renderizar();
		fpsManager.stop();
	}
}



void Juego::renderizar() {

	entorno.renderizarTodo(nanobot,lista);
}



void Juego::limpiar(){

    entorno.limpiar();
}

// Se encarga de manejar los eventos de teclado a traves de la clase "InputManager"
// En general, para saber si una tecla esta siendo presionada se utilizara
// el metodo "isKeyDown(KEY)". Para saber que KEY pasar por parametro, consultar
// el archivo "InputTable.h" que mapea codigos de teclado de SDL.
void Juego::manejarEventos() {

	InputManager* inputManager = InputManager::getInstance();
    inputManager->update();
    if(inputManager->quitRequested()) running = false;

    if(inputManager->isKeyDown(KEY_C)||entorno.dosisAExplotando())
    {
        entorno.explotarDosis(A);
    }
    if((inputManager->isKeyDown(KEY_B)||entorno.dosisBExplotando()))
    {
        entorno.explotarDosis(B);
    }
    /*if((inputManager->isKeyDown(KEY_SPACE)) && intersececion_n(nanobot,anticuerpo)){
        if(anticuerpo.obtener_moverse() == 1)
            anticuerpo.asignar_moverse(0);
        else
            anticuerpo.asignar_moverse(1);
    }*/
    if(inputManager->isKeyDown(KEY_RIGHT) && nanobot.get_x()<(SCREEN_WIDTH-NANOBOT_WIDTH))
    {
        nanobot.rigth();
    }
    if(inputManager->isKeyDown(KEY_LEFT) && nanobot.get_x()>0)
    {
        nanobot.left();
    }
    if(inputManager->isKeyDown(KEY_UP) && nanobot.get_y()>0)
    {
        nanobot.up();
    }
    if(inputManager->isKeyDown(KEY_DOWN) && nanobot.get_y()<(SCREEN_HEIGHT-NANOBOT_HEIGHT))
    {
        nanobot.down();
    }

}

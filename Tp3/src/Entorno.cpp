#include "Entorno.h"


#include<iostream>
using namespace std;

#include "Constants.h"
#include"InputManager.h"


Entorno::Entorno()
{
    estadoDosisA = 1;
    estadoDosisB = 1;
    loaderA = new ImageLoader(COMMON_RED, COMMON_GREEN,COMMON_BLUE);
    loaderB = new ImageLoader(SECONDARY_RED,SECONDARY_GREEN,SECONDARY_BLUE);
}

bool Entorno::iniciar(const char *title, int xpos, int ypos, int flags)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {

    cerr<<"SDL no se pudo inicializar."<<endl;
    return false;

    } else {

        window = SDL_CreateWindow(title, xpos, ypos, SCREEN_WIDTH, SCREEN_HEIGHT, flags);
        if (window == 0) {

        	cerr<<"Fallo al crear ventana."<<endl;
            return false;

        } else {

            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (renderer == 0) {
            	cerr<<"Fallo al crear Renderer"<<endl;

                return false;
            } else {

                int imgFlags = IMG_INIT_PNG;
                if (!(IMG_Init(imgFlags) & imgFlags)) {
                	cerr<<"SDL_image no pudo inicializarse."<<endl;
                    return false;
                }
                cargarTexturas();
            }
        }
    }
    // everything inited successfully,
    return true;
}


void Entorno::renderizar(imagenes imagen,float x, float y)
{
    switch(imagen)
    {
        case FONDO:
            texturas[FONDO].render(x,y,SCREEN_WIDTH,SCREEN_HEIGHT,renderer);
            break;
        case NANOBOT:
            texturas[NANOBOT].render(x,y,NANOBOT_WIDTH,NANOBOT_HEIGHT,renderer);
            break;
        case CELULA_S:
            texturas[CELULA_S].render(x,y,CELULA_SIZE,CELULA_SIZE,renderer);
            break;
        case CELULA_X:
            texturas[CELULA_X].render(x,y,CELULA_SIZE,CELULA_SIZE,renderer);
            break;
        case CELULA_Y:
            texturas[CELULA_Y].render(x,y,CELULA_SIZE,CELULA_SIZE,renderer);
            break;
        case CELULA_Z:
            texturas[CELULA_Z].render(x,y,CELULA_SIZE,CELULA_SIZE,renderer);
            break;
        case ANTICUERPO:
            texturas[ANTICUERPO].render(x,y,ANTICUERPO_WIDTH,ANTICUERPO_HEIGHT,renderer);
            break;
        case DOSIS_A:
            if(estadoDosisA<LAST_DOSIS_SPRITE)
                texturas[DOSIS_A].render(x,y,DOSIS_WIDTH,DOSIS_HEIGHT,renderer);
            break;
        case DOSIS_B:
            if(estadoDosisB<LAST_DOSIS_SPRITE)
                texturas[DOSIS_B].render(x,y,DOSIS_WIDTH,DOSIS_HEIGHT,renderer);
            break;

    }
}

void Entorno::cargarTexturas()
{
    for(int i=0;i<7;i++)
    {
        texturas[i].cargarDesdeArchivo(PATHS[i],renderer);
    }
    loaderA->loadSprite(DOSIS_PATH,estadoDosisA,renderer,&texturas[DOSIS_A]);
    loaderB->loadSprite(DOSIS_PATH,estadoDosisB,renderer,&texturas[DOSIS_B]);
}

Entorno::~Entorno()
{
	window = NULL;
	renderer = NULL;
}
//,Celula* c1,Celula* c2,Celula* c3

void Entorno::renderizarTodo(Nanobot nanobot,Lista* lista){

  SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(renderer); // clear the renderer to the draw color
	renderizar(FONDO,0,0);
	renderizar(NANOBOT,nanobot.get_x(),nanobot.get_y());


	//Prepara el Draw para dibujar una linea negra
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);

    //Inserte codigo para dibujar lineas
    for(int i=1;i<=lista->obtener_cantidad_celulas();i++){
        SDL_RenderDrawLine(renderer, obtener_posicion_x(lista,i-1)+(CELULA_SIZE/2), obtener_posicion_y(lista,i-1)+(CELULA_SIZE/2), obtener_posicion_x(lista,i)+(CELULA_SIZE/2), obtener_posicion_y(lista,i)+(CELULA_SIZE/2));
        if( (i%2 != 0) && (i != 1) )
            SDL_RenderDrawLine(renderer,obtener_posicion_x(lista,i-2)+(CELULA_SIZE/2),obtener_posicion_y(lista,i-2)+(CELULA_SIZE/2),obtener_posicion_x(lista,i)+(CELULA_SIZE/2),obtener_posicion_y(lista,i)+(CELULA_SIZE/2));
    }

    //Inserte codigo para renderizar imagenes
    int i = 0;
    Nodo* nodo = lista->obtener_nodo(1);
    
    while( i < lista->obtener_tamanio() ){
        //Pense un switch case para graficar segun lo que tenga que graficar pero no supo como hacerlo

        Elementos* elemento = nodo->obtener_dato();

        int id = elemento->obtener_id();
        int pos_x = elemento->get_posicion_x();
        int pos_y = elemento->get_posicion_y();

        renderizar( id, pos_x, pos_y );

        nodo = nodo->obtener_siguiente();
        i++;
    }

	SDL_RenderPresent(renderer); // draw to the screen

}

void Entorno::limpiar()
{
    for(int i=0;i<7;i++)
        texturas[i].free();
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

}

void Entorno::explotarDosis(dosis dosis)
{
    switch(dosis){
        case A:
            if(estadoDosisA<=LAST_DOSIS_SPRITE){
                this->loaderA->loadSprite(DOSIS_PATH,estadoDosisA,renderer,&texturas[DOSIS_A]);
                ++estadoDosisA;
            }
        break;

        case B:
            if(estadoDosisB<=LAST_DOSIS_SPRITE){
                this->loaderB->loadSprite(DOSIS_PATH,estadoDosisB,renderer,&texturas[DOSIS_B]);
                ++estadoDosisB;
            }
    }
}

bool Entorno::dosisAExplotando()
{
    return estadoDosisA>1;
}

bool Entorno::dosisBExplotando()
{
    return estadoDosisB>1;
}

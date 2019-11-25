
#include "Nanobot.h"

Nanobot::Nanobot(){

}
void Nanobot::asignar_x(int pos_x){
    this->pos_x=pos_x;
}
void Nanobot::asignar_y(int pos_y){
    this->pos_y=pos_y;
}
void Nanobot::up(){
    pos_y=pos_y-10;
}
void Nanobot::down(){
    pos_y=pos_y+10;
}
void Nanobot::rigth(){
    pos_x=pos_x+10;
}
void Nanobot::left(){
    pos_x=pos_x-10;
}
int Nanobot::get_y(){
    return pos_y;
}
int Nanobot::get_x(){
    return pos_x;
}
Nanobot::~Nanobot(){
}


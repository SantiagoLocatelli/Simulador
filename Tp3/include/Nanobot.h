#ifndef NANOBOT_H_INCLUDED
#define NANOBOT_H_INCLUDED
#include "DosisA.h"
#include "DosisB.h"


class Nanobot {

private:
    DosisA dosisA;
    DosisB dosisB;
    int pos_x,pos_y;

public:
    Nanobot();

    void asignar_x(int pos_x);
    void asignar_y(int pos_y);

    void up();
    void down();
    void rigth();
    void left();

    int get_y();
    int get_x();

    ~Nanobot();

};

#endif // NANOBOT_H_INCLUDED

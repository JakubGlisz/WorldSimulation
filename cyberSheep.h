#pragma once
#include "Animal.h"

class cyberSheep : public Animal {
public:
    char draw();
    cyberSheep(int x_, int y_);
    void action(World *w);
};
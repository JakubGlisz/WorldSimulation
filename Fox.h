#pragma once
#include "Animal.h"

class Fox : public Animal {
public:
    Fox(int x_, int y_);
    char draw();
    void action(World *w);
};
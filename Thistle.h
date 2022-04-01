#pragma once
#include "Plant.h"

class Thistle : public Plant {
public:
    void action(World *w);
    Thistle(int x_, int y_);
    char draw();
};
#pragma once
#include "Plant.h"

class Grass : public Plant {
public:
    void action(World *w);
    Grass(int x_, int y_);
    char draw();
};
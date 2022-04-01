#pragma once
#include "Plant.h"

class Belladonna : public Plant {
public:
    void action(World *w);
    collisionResult collision(Organism* attacker);
    Belladonna(int x_, int y_);
    char draw();
};
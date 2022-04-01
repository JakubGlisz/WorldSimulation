#pragma once
#include "Plant.h"

class Guarana : public Plant {
public:
    void action(World *w);
    collisionResult collision(Organism* attacker);
    Guarana(int x_, int y_);
    char draw();
};
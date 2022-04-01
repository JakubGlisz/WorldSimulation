#pragma once
#include "Animal.h"

class Antelope : public Animal {
public:
    Antelope(int x_, int y_);
    char draw();
    void action(World *w);
    collisionResult collision(Organism* attacker);
};
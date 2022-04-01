#pragma once
#include "Animal.h"

class Turtle : public Animal {
public:
    Turtle(int x_, int y_);
    char draw();
    void action(World *w);
    collisionResult collision(Organism* attacker);
};
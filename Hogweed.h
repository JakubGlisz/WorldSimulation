#pragma once
#include "Plant.h"

class Hogweed : public Plant {
public:
    void action(World *w);
    collisionResult collision(Organism* attacker);
    Hogweed(int x_, int y_);
    char draw();
};
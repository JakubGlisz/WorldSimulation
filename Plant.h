#pragma once
#include "Organisms.h"
#include "World.h"

class Plant : public Organism {
public:
    Plant(int strength, position_t position);
    ~Plant();
    void action(World *w);
    collisionResult collision(Organism* attacker);
    char draw();
};

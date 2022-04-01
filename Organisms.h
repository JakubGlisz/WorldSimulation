#pragma once
#include "Types.h"
#include "World.h"

class Organism {
public:
    int initiativeIndex;
    int strength;
    int initiative;
    int age = 0;
    position_t position;
    virtual void action(World *w) = 0;
    virtual collisionResult collision(Organism* collider) = 0;
    virtual char draw() = 0;

    Organism(int strength, int initiative, position_t position);
};


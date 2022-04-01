#pragma once
#include "Organisms.h"
#include "World.h"

class Animal : public Organism {
public:
    ~Animal();
    Animal(int strength, int initiative, position_t position);
    void action(World *w);
    collisionResult collision(Organism* attacker);
    char draw();
};

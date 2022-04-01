#pragma once
#include "Animal.h"
#include "World.h"

class Human : public Animal {
public:
    int lastAbilityUsage = 0;
    int strengthBonus = 0;
    Human(int x_, int y_);
    char draw();
    void action(World *w);
};
#pragma once
#include "Animal.h"

class Sheep : public Animal {
public:
    Sheep(int x_, int y_);
    char draw();
};
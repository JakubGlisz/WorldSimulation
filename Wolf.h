#pragma once
#include "Animal.h"

class Wolf : public Animal {
public:
    Wolf(int x_, int y_);
    char draw();
};
#pragma once
#include "Sheep.h"

char Sheep::draw() {
	return 'S';
}

Sheep::Sheep(int x_, int y_)
	: Animal(4, 4, position_t(x_, y_))
{}
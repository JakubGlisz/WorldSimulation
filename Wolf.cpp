#pragma once
#include "Wolf.h"

char Wolf::draw() {
	return 'W';
}

Wolf::Wolf(int x_, int y_)
	: Animal(9, 5, position_t(x_, y_))
{}
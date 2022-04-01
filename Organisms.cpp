#pragma once
#include <iostream>
#include <stdlib.h>
#include "Organisms.h"

using namespace std;


Organism::Organism(int strength, int initiative, position_t position)
{
	this->strength = strength;
	this->initiative = initiative;
	this->position = position;
}

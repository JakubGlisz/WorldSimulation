#pragma once
#include "Turtle.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

char Turtle::draw() {
	return 'T';
}

void Turtle::action(World *w) {
	int random = rand() % 101;
	if (random >= 75) {
		Animal::action(w);
	}
}

collisionResult Turtle::collision(Organism* attacker) {
	
	if(this->draw() == attacker->draw()) {
		if(this->age > 3 && attacker->age > 3) {
			return BREED;
		}
		/*else {
			return DEFEND;
		}*/
	}

	if (attacker->strength < 5) {
		return DEFEND;
	}

	if (attacker->strength >= this->strength) {
		return DEAD;
	}
	else {
		return KILL;
	}
}

Turtle::Turtle(int x_, int y_)
	: Animal(2, 1, position_t(x_, y_))
{}
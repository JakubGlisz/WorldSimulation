#pragma once
#include "Antelope.h"
#include <iostream>

using namespace std;

char Antelope::draw() {
	return 'A';
}

void Antelope::action(World *w) {
	Animal::action(w);
	Animal::action(w);
}

collisionResult Antelope::collision(Organism* attacker) {
	
	if(this->draw() == attacker->draw()) {
		if(this->age > 3 && attacker->age > 3) {
			return BREED;
		}
		/*else {
			return DEFEND;
		}*/
	}

	if (attacker->strength >= this->strength) {
		if (rand() % 2 == 0) {
			return DEAD;
		}
		else {
			return ESCAPE;
		}
	}
	else {
		return KILL;
	}
}

Antelope::Antelope(int x_, int y_)
	: Animal(4, 4, position_t(x_, y_))
{}
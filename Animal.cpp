#pragma once
#include <iostream>
#include <stdlib.h>
#include "Animal.h"

using namespace std;

void Animal::action(World *w) {
	int direction = rand() % 2;
	int randomX = rand() % 2;
	int randomY = rand() % 2;

	if (direction == 1) {
		if (randomX == 0 && this->position.x > 0) {
			this->position.x -= 1;
		}
		else if (randomX == 1 && this->position.x + 1 < WORLD_WIDTH) {
			this->position.x += 1;
		}
	}
	else {
		if (randomY == 0 && this->position.y > 0) {
			this->position.y -= 1;
		}
		else if (randomY == 1 && this->position.y + 1 < WORLD_HEIGHT) {
			this->position.y += 1;
		}
	}

};

collisionResult Animal::collision(Organism* attacker) {

	int initialX = this->position.x;
	int initialY = this->position.y;

	if(this->draw() == attacker->draw()) {
		if(this->age > 3 && attacker->age > 3) {
			return BREED;
		}
		/*else { // Animals under age 3 may be killed by the same species, it prevents overpopulation
			return DEFEND;
		}*/
	}
	if (attacker->strength >= this->strength) {
		return DEAD;
	}
	else {
		return KILL;
	}
}

char Animal::draw() {
	return 'X';
}

Animal::Animal(int strength, int initiative, position_t position)
	: Organism(strength, initiative, position)
{}

Animal::~Animal() {
	delete this;
}
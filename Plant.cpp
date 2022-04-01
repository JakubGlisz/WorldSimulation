#pragma once
#include <iostream>
#include <stdlib.h>
#include "Plant.h"

using namespace std;

void Plant::action(World *w) {
	int thisX = this->position.x;
	int thisY = this->position.y;
	w->board[thisY][thisX].occupant = this;
	int random = rand() % 101;
	if(random < SPREADING_RATE) {
		int direction = rand() % 2;
		int randomX = rand() % 2;
		int randomY = rand() % 2;

		if (direction == 1) {
			if (randomX == 0 && thisX > 0) {
				thisX -= 1;
			}
			else if (randomX == 1 && thisX + 1 < WORLD_WIDTH) {
				thisX += 1;
			}
		}
		else {
			if (randomY == 0 && thisY > 0) {
				thisY -= 1;
			}
			else if (randomY == 1 && thisY + 1 < WORLD_HEIGHT) {
				thisY += 1;
			}
		}

		if(w->board[thisY][thisX].occupant == NULL) {
			w->addOrganism(new Plant(0, position_t(thisX,thisY)));
		}
	}
};

collisionResult Plant::collision(Organism* attacker) {
    
	if (attacker->strength >= this->strength) {
		return DEAD;
	}
	else {
		return KILL;
	}
}

char Plant::draw() {
	return 'P';
}

Plant::~Plant() {
	delete this;
}

Plant::Plant(int strength, position_t position)
	: Organism(strength, 0, position)
{}

#pragma once
#include "Fox.h"
#include <stdlib.h>

char Fox::draw() {
	return 'F';
}

void Fox::action(World *w) {
	int initialX = this->position.x;
	int initialY = this->position.y;
	int randomX = rand() % 2;
	int randomY = rand() % 2;

	Animal::action(w);


	if (w->board[this->position.y][this->position.x].occupant != NULL) {
		if (w->board[this->position.y][this->position.x].occupant->strength > this->strength) {
			this->position.x = initialX;
			this->position.y = initialY;
		}
	}
}

Fox::Fox(int x_, int y_)
	: Animal(3, 7, position_t(x_, y_))
{}
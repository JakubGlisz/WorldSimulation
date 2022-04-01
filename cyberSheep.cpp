#pragma once
#include "cyberSheep.h"
#include "Hogweed.h"
#include <math.h>

char cyberSheep::draw() {
	return 'C';
}

void cyberSheep::action(World *w) {
	int distance = 9999;
	int tmp;
	int index;

	for(int i = 0; i < w->allOrganisms.size(); i++) {
		if(dynamic_cast<Hogweed*>(w->allOrganisms[i])) {
			tmp = abs(this->position.x - w->allOrganisms[i]->position.x) + 
				abs(this->position.y - w->allOrganisms[i]->position.y);
			if(tmp < distance) {
				distance = tmp;
				index = i;
			}
		}
	}

	if(distance == 9999) {
		Animal::action(w);
		return;
	}

	if(w->allOrganisms[index]->position.x > this->position.x) {
		this->position.x += 1;
		return;
	}
	else if(w->allOrganisms[index]->position.x < this->position.x) {
		this->position.x -= 1;
		return;
	}
	else if(w->allOrganisms[index]->position.x == this->position.x) {
		if(w->allOrganisms[index]->position.y > this->position.y) {
			this->position.y += 1;
			return;
		}
		else if(w->allOrganisms[index]->position.y < this->position.y) {
			this->position.y -= 1;
			return;
		}
	}
}

cyberSheep::cyberSheep(int x_, int y_)
	: Animal(11, 4, position_t(x_, y_))
{}

#pragma once
#include "Thistle.h"
#include <stdlib.h>

char Thistle::draw() {
	return '*';
}

void Thistle::action(World *w) {
	int thisX = this->position.x;
	int thisY = this->position.y;
	w->board[thisY][thisX].occupant = this;
    for(int i = 0; i < 3; i++) {
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
                w->addOrganism(new Thistle(thisX, thisY));
            }
        }
    }
};

Thistle::Thistle(int x_, int y_)
	: Plant(0, position_t(x_, y_))
{}
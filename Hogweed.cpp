#pragma once
#include "Hogweed.h"
#include <stdlib.h>

char Hogweed::draw() {
	return '#';
}

collisionResult Hogweed::collision(Organism* attacker) {
    
	if(attacker->draw() == 'C') {
		return DEAD;
	}
	else {
		return KILL;
	}
}

void Hogweed::action(World *w) {
    
	int thisX = this->position.x;
	int thisY = this->position.y;
    w->board[thisY][thisX].occupant = this;
    
    if (thisX > 0) {
        if(w->board[thisY][thisX-1].occupant != NULL) {
            if(w->board[thisY][thisX-1].occupant->draw() != 'C') { // dynamic_cast<cyberSheep*> (w->board[thisY][thisX-1].occupant)
                w->delOrganism(w->board[thisY][thisX-1].occupant->initiativeIndex);
            }
        }
	}
	if (thisX + 1 < WORLD_WIDTH) {
        if(w->board[thisY][thisX+1].occupant != NULL) {
            if(w->board[thisY][thisX+1].occupant->draw() != 'C') {
                w->delOrganism(w->board[thisY][thisX+1].occupant->initiativeIndex);
            }
        }
	}
	if (thisY > 0) {
        if(w->board[thisY-1][thisX].occupant != NULL) {
            if(w->board[thisY-1][thisX].occupant->draw() != 'C') {
                w->delOrganism(w->board[thisY-1][thisX].occupant->initiativeIndex);
            }
        }
	}
	if (thisY + 1 < WORLD_HEIGHT) {
        if(w->board[thisY+1][thisX].occupant != NULL) {
            if(w->board[thisY+1][thisX].occupant->draw() != 'C') {
                w->delOrganism(w->board[thisY+1][thisX].occupant->initiativeIndex);
            }
        }
	}

	/*w->board[thisY][thisX].occupant = this;
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
			w->addOrganism(new Guarana(thisX, thisY));
		}
	}*/
};

Hogweed::Hogweed(int x_, int y_)
	: Plant(10, position_t(x_, y_))
{}
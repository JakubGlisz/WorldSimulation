#pragma once
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "Human.h"

using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define ENTER 13

char Human::draw() {
	return 'H';
}

void Human::action(World *w) {
	int option = 0;
	if(this->strengthBonus > 0) {
		this->strengthBonus -= 1;
		this->strength -= 1;
	}
	cout << "human strength: " << this->strength << endl;
	if((this->lastAbilityUsage == 0 || (this->age - this->lastAbilityUsage) > 10)) {
		cout << "[0] ABILITY" << endl;
	}
	cout << "[1] UP" << endl;
	cout << "[2] DOWN" << endl;
	cout << "[3] LEFT" << endl;
	cout << "[4] RIGHT" << endl;
	cout << "[5] SAVE" << endl;
	cout << "[6] LOAD SAVE" << endl;
	cout << "[7] SKIP" << endl;
	cin >> option;
	switch (option/*=getch()*/) {
	case 0:
		if(this->lastAbilityUsage == 0 || this->age - this->lastAbilityUsage > 10) {
			this->lastAbilityUsage = this->age;
			if(this->strength < 10) {
				this->strengthBonus = 11 - this->strength;
				this->strength += this->strengthBonus;
			}
		}
		break;
	case 1:
		if (this->position.y > 0) {
			this->position.y -= 1;
		}
		break;
	case 2:
		if (this->position.y + 1 < WORLD_HEIGHT) {
			this->position.y += 1;
		}
		break;
	case 3:
		if (this->position.x > 0) {
			this->position.x -= 1;
		}
		break;
	case 4:
		if (this->position.x + 1 < WORLD_WIDTH) {
			this->position.x += 1;
		}
		break;
	case 5:
		w->saveWorld();
		break;
	case 6:
		w->loadSave();
		break;
	case 7:
		break;
	}
}

Human::Human(int x_, int y_)
	: Animal(5, 4, position_t(x_, y_))
{}

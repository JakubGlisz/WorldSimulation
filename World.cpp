#pragma once
#include "World.h"
#include "Organisms.h"
#include "Animal.h"
#include "Sheep.h"
#include "Wolf.h"
#include "Fox.h"
#include "cyberSheep.h"
#include "Turtle.h"
#include "Antelope.h"
#include "Human.h"
#include "Thistle.h"
#include "Guarana.h"
#include "Belladonna.h"
#include "Hogweed.h"
#include "Grass.h"

void World::handleCollisions(int initialX, int initialY) {
    // if cell is empty, just change position, else do collision
    if(board[allOrganisms[currentOrganismIndex]->position.y][allOrganisms[currentOrganismIndex]->position.x].occupant == NULL) {
        board[allOrganisms[currentOrganismIndex]->position.y][allOrganisms[currentOrganismIndex]->position.x].occupant = allOrganisms[currentOrganismIndex];
    }
    else {
        collisionResult result = board[allOrganisms[currentOrganismIndex]->position.y][allOrganisms[currentOrganismIndex]->position.x].occupant->collision(allOrganisms[currentOrganismIndex]);
        // result = KILL currentOrganism is killed
        // result = DEAD currentOrganism kills the organism that is occupying the cell
        // result = DEFEND currentOrganism's attack was reflected
        // result = ESCAPE occupant escapes
        if(result == KILL) {
            events += board[allOrganisms[currentOrganismIndex]->position.y][allOrganisms[currentOrganismIndex]->position.x].occupant->draw();
            events += " killed ";
            events += allOrganisms[currentOrganismIndex]->draw();
            events += "\n";
            delOrganism(currentOrganismIndex);
        }
        else if(result == DEAD) {
            events += allOrganisms[currentOrganismIndex]->draw();
            events += " killed ";
            events +=  board[allOrganisms[currentOrganismIndex]->position.y][allOrganisms[currentOrganismIndex]->position.x].occupant->draw();
            events += "\n";
            delOrganism(board[allOrganisms[currentOrganismIndex]->position.y][allOrganisms[currentOrganismIndex]->position.x].occupant->initiativeIndex);
            board[allOrganisms[currentOrganismIndex]->position.y][allOrganisms[currentOrganismIndex]->position.x].occupant = allOrganisms[currentOrganismIndex];
        }
        else if(result == DEFEND) {
            events += board[allOrganisms[currentOrganismIndex]->position.y][allOrganisms[currentOrganismIndex]->position.x].occupant->draw();
            events += " defended himself against ";
            events +=  + allOrganisms[currentOrganismIndex]->draw();
            events += "\n";
            allOrganisms[currentOrganismIndex]->position.x = initialX;
            allOrganisms[currentOrganismIndex]->position.y = initialY;
            board[initialY][initialX].occupant = allOrganisms[currentOrganismIndex];
        }
        else if(result == ESCAPE) {
            events += board[allOrganisms[currentOrganismIndex]->position.y][allOrganisms[currentOrganismIndex]->position.x].occupant->draw();
            events += " escaped from fight with ";
            events += allOrganisms[currentOrganismIndex]->draw();
            events += "\n";
            board[initialY][initialX].occupant = board[allOrganisms[currentOrganismIndex]->position.y][allOrganisms[currentOrganismIndex]->position.x].occupant;
            board[initialY][initialX].occupant->position.x = initialX;
            board[initialY][initialX].occupant->position.y = initialY;
            board[allOrganisms[currentOrganismIndex]->position.y][allOrganisms[currentOrganismIndex]->position.x].occupant = allOrganisms[currentOrganismIndex];
        }
        else if(result == BREED) {
            events += allOrganisms[currentOrganismIndex]->draw();
            events += " are breeding \n";
            Organism *a = returnChild(allOrganisms[currentOrganismIndex], initialX, initialY);

            allOrganisms[currentOrganismIndex]->position.x = initialX;
            allOrganisms[currentOrganismIndex]->position.y = initialY;
            board[initialY][initialX].occupant = allOrganisms[currentOrganismIndex];
            if (initialX > 0 && board[initialY][initialX-1].occupant == NULL) {
                a->position.x -= 1;
                addOrganism(a);
            }
            else if (initialX + 1 < WORLD_WIDTH && board[initialY][initialX+1].occupant == NULL) {
                a->position.x += 1;
                addOrganism(a);
            }
            else if (initialY > 0 && board[initialY-1][initialX].occupant == NULL) {
                a->position.y -= 1;
                addOrganism(a);
            }
            else if (initialY + 1 < WORLD_HEIGHT && board[initialY+1][initialX].occupant == NULL) {
                a->position.y += 1;
                addOrganism(a);
            }
        }
    }
}

Organism *charToOrganism(char arg, int x_, int y_) {
    switch(arg) {
        case 'H':
            return new Human(x_, y_);
            break;
        case 'S':
            return new Sheep(x_, y_);
            break;
        case 'W':
            return new Wolf(x_, y_);
            break;
        case 'F':
            return new Fox(x_, y_);
            break;
        case 'T':
            return new Turtle(x_, y_);
            break;
        case 'A':
            return new Antelope(x_, y_);
            break;
        case 'C':
            return new cyberSheep(x_, y_);
            break;
        case 'G':
            return new Grass(x_, y_);
            break;
        case '*':
            return new Thistle(x_, y_);
            break;
        case '+':
            return new Guarana(x_, y_);
            break;
        case '!':
            return new Belladonna(x_, y_);
            break;
        case '#':
            return new Hogweed(x_, y_);
            break;
        default:
            return new Animal(4, 4, position_t(x_, y_));
            break;
    }
}

void World::saveWorld() {
    FILE *fptr;
    fptr = (fopen("save.txt", "w"));

    if(NULL == fptr) {
        cout << "Failed to open the file" << endl;
        return;
    }

    for(int i = 0; i < this->allOrganisms.size(); i++) {
        fprintf(fptr, "%c %i %i\r\n", this->allOrganisms[i]->draw(), this->allOrganisms[i]->position.x, this->allOrganisms[i]->position.y);
    }

    fclose(fptr);
}

void World::loadSave() {
    char c;
    int x;
    int y;

    FILE *fptr;
    fptr = (fopen("save.txt", "r"));

    if(NULL == fptr) {
        cout << "Failed to open the file" << endl;
        return;
    }

    while(this->allOrganisms.size() != 0) {
        delOrganism(0);
    }

    while(fscanf(fptr, "%c %i %i\r\n", &c, &x, &y) != EOF) {
        addOrganism(charToOrganism(c, x, y));
    }
    system("cls");
    drawWorld();

    fclose(fptr);
}

bool comparator(const Organism* lhs, const Organism* rhs) {
    return lhs->initiative > rhs->initiative;
}

bool World::isHumanAllive() {
    for(int i = 0; i < this->allOrganisms.size(); i++) {
        if(dynamic_cast<Human*>(allOrganisms[i])) {
            return 1;
        }
    }
    return 0;
}

Organism *World::returnChild(Organism *organism_, int x_, int y_) {

    if(dynamic_cast<Sheep*>(organism_)) {
        return new Sheep(x_, y_);
    }
    else if(dynamic_cast<Wolf*>(organism_)) {
        return new Wolf(x_, y_);
    }
    else if(dynamic_cast<Fox*>(organism_)) {
        return new Fox(x_, y_);
    }
    else if(dynamic_cast<cyberSheep*>(organism_)) {
        return new cyberSheep(x_, y_);
    }
    else if(dynamic_cast<Turtle*>(organism_)) {
        return new Turtle(x_, y_);
    }
    else if(dynamic_cast<Antelope*>(organism_)) {
        return new Antelope(x_, y_);
    }

    return new Animal(4, 4, position_t(x_, y_));
}

void World::addOrganism(Organism *organism_) {
    if(board[organism_->position.y][organism_->position.x].occupant == NULL) {
        allOrganisms.push_back(organism_);
        sort(allOrganisms.begin(), allOrganisms.end(), &comparator);
        for(int i = 0; i < allOrganisms.size(); i++) {
            allOrganisms[i]->initiativeIndex = i;
        }
        board[organism_->position.y][organism_->position.x].occupant = organism_;
    }
}

void World::delOrganism(int index) {
    board[allOrganisms[index]->position.y][allOrganisms[index]->position.x].occupant = NULL;
    allOrganisms.erase(allOrganisms.begin() + index);
    sort(allOrganisms.begin(), allOrganisms.end(), &comparator);
    for(int i = 0; i < allOrganisms.size(); i++) {
        allOrganisms[i]->initiativeIndex = i;
    }
}

void World::makeTurn() {
    int initialX = allOrganisms[currentOrganismIndex]->position.x;
    int initialY = allOrganisms[currentOrganismIndex]->position.y;
    board[allOrganisms[currentOrganismIndex]->position.y][allOrganisms[currentOrganismIndex]->position.x].occupant = NULL;
    
    allOrganisms[currentOrganismIndex]->action(this);
    allOrganisms[currentOrganismIndex]->age += 1;

    // if organism stays in place just skip to the next round
    if(board[allOrganisms[currentOrganismIndex]->position.y][allOrganisms[currentOrganismIndex]->position.x].occupant == allOrganisms[currentOrganismIndex]) {
        if(currentOrganismIndex + 1 < allOrganisms.size()){
            currentOrganismIndex++;
        }
        else {
            currentOrganismIndex = 0;
        }
        return;
    }

    handleCollisions(initialX, initialY);

    if(currentOrganismIndex + 1 < allOrganisms.size()){
        currentOrganismIndex++;
    }
    else {
        currentOrganismIndex = 0;
    }
    
}

void World::drawWorld() {
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            if(board[i][j].occupant == NULL) {
                cout << board[i][j].tile;
            }
            else {
                cout << board[i][j].occupant->draw();
            }
        }
        cout << endl;
    }
}

World::World(int width = 10, int height = 10)
: height(height), width(width), currentOrganismIndex(0)
{
    board = new board_t*[height];
    for(int i = 0; i < height; i++) {
        board[i] = new board_t[width];
    }
}
World::~World() {
    for(int i = 0; i < height; i++) {
        delete [] board[i];
    }
    delete [] board;
}

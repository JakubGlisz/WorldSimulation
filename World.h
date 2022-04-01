#pragma once
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include "Organisms.h"

using namespace std;

class World {
    public:
        vector<Organism*> allOrganisms;
        string events;
        int currentOrganismIndex;
        int height;
        int width;
        board_t **board;

        Organism *returnChild(Organism *organism_, int x_, int y_);

        void addOrganism(Organism *organism_);

        void delOrganism(int index);

        void makeTurn();

        void handleCollisions(int initialX, int initialY);
        
        void drawWorld();

        void saveWorld();

        void loadSave();

        bool isHumanAllive();

        World(int width, int height);
        ~World();
};
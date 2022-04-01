#pragma once


#define WORLD_WIDTH 30
#define WORLD_HEIGHT 8

#define SPREADING_RATE 15 // plant spreading, lowest 0-100 highest

class Organism; 
class World;

enum collisionResult { DEAD, KILL, DEFEND, ESCAPE, BREED };

struct board_t {
    char tile = '.';
    Organism* occupant = nullptr;
};

struct position_t {
    int x;
    int y;

    position_t() {
        x = 0;
        y = 0;
    }

    position_t(int x_, int y_) {
        x = x_;
        y = y_;
    }
};




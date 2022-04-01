#pragma once
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include "Organisms.h"
#include "Animal.h"
#include "Human.h"
#include "Wolf.h"
#include "Fox.h"
#include "Sheep.h"
#include "Turtle.h"
#include "Antelope.h"
#include "cyberSheep.h"
#include "Plant.h"
#include "World.h"
#include "Grass.h"
#include "Thistle.h"
#include "Guarana.h"
#include "Belladonna.h"
#include "Hogweed.h"

using namespace std;

void printInfo() {
    cout << "+---------------------------+" << endl;
    cout << "| Jakub Gliszczynski 184370 |" << endl;
    cout << "+---------------------------+" << endl;
    cout << "X - default Animal (not implemented)" << endl;
    cout << "H - Human" << endl;
    cout << "S - Sheep" << endl;
    cout << "F - Fox" << endl;
    cout << "T - Turtle" << endl;
    cout << "A - Antelope" << endl;
    cout << "C - Cyber Sheep" << endl;
    cout << "G - Grass" << endl;
    cout << "* - Thistle" << endl;
    cout << "+ - Guarana" << endl;
    cout << "! - Belladonna" << endl;
    cout << "# - Hogweed" << endl;
}

int main() {

    srand(time(NULL));

    World w(WORLD_WIDTH, WORLD_HEIGHT);
    Human h(1,1);
    Wolf wol(5, 5);
    Wolf wol2(10, 4);
    Sheep s(29, 7);
    Sheep s2(25, 6);
    Fox f(15, 2);
    Fox f2(20, 1);
    Turtle t(1, 3);
    Turtle t2(1, 5);
    Antelope a(4, 2);
    Antelope a2(20, 4);
    cyberSheep c(5, 7);
    Grass gr(7,7);
    Grass gr2(18,0);
    Thistle th(25, 5);
    Guarana gu(0,0);
    Belladonna be(15,5);
    Hogweed ho(10,1);
    Hogweed ho2(13,1);

    w.addOrganism(&h);
    w.addOrganism(&wol);
    w.addOrganism(&wol2);
    w.addOrganism(&s);
    w.addOrganism(&s2);
    w.addOrganism(&f);
    w.addOrganism(&f2);
    w.addOrganism(&t);
    w.addOrganism(&t2);
    w.addOrganism(&a);
    w.addOrganism(&a2);
    w.addOrganism(&c);
    w.addOrganism(&gr);
    w.addOrganism(&gr2);
    w.addOrganism(&th);
    w.addOrganism(&gu);
    w.addOrganism(&be);
    w.addOrganism(&ho);
    w.addOrganism(&ho2);

    printInfo();
    w.drawWorld();

    while(1) {
        for(int i = 0; i < w.allOrganisms.size(); i++) {
            w.makeTurn();
        }
        system("cls");
        printInfo();
        w.drawWorld();
        cout << w.events << endl;
        w.events = "";

        if(!w.isHumanAllive()) {
            cout << "Human is dead :c" << endl;
            exit(0);
        }
    }

    return 0;
}

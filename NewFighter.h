//============================================================================
// Name        : Fighter.h
// Author      : Hamza, Kazz
// Version     : 24/11/10
// Copyright   : >:o
// Description : Fighter Class
//============================================================================
#pragma once

#include <iostream>
#include <random>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

class Fighter;

class Fighters {
    public:
        Fighters(int numFighters=3);
        ~Fighters();

        void checkFighterStats();
        Fighter& pickFighter();

        void ReRoll(int fighterIndex);
        void ReRollAll();

    private:
        std::vector<Fighter> fighters;
};

class Fighter {
    public:
        Fighter();
        ~Fighter();

        void ReRoll();

        int HP();
        int Attack();
    private:

        int _HP;
        int _Attack;   
};

// Implementation -- Should be in .cpp file
Fighters::Fighters(int numFighters) {
     //srand(time(0)); //seeding the randomness so its random every time
    //DO NOT DO THIS ^^^^, put the srand(time(0)) in the main so it only has to seed the randomness once;
    srand(time(0));
    for ( int i=0; i < numFighters; i++ ) {
        fighters.push_back(Fighter());
    }
}

Fighters::~Fighters() {

}

void Fighters::ReRoll(int fighterIndex) {
    fighters[fighterIndex].ReRoll();

    std::cout << "New stats for Fighter " << fighterIndex + 1 << ":\n";
    std::cout << "HP: " << fighters[fighterIndex].HP() << "\n";
    std::cout << "Strength: " << fighters[fighterIndex].Attack() << "\n";
}

void Fighters::ReRollAll() {
    for (int i = 0; i < fighters.size(); i++) {
        ReRoll(i);
    }
}

void Fighters::checkFighterStats(){
    for (int i = 0; i < fighters.size(); i++) {  
        cout << "║" << "Figher " << i + 1 << " Stats: ║" << "   ";
    }

    cout << endl;

    for (int i = 0; i < fighters.size(); i++) {
        cout << "║" << "HP: " << setw(2) << fighters[i].HP() << setw(13) << "║" << "   ";
    }

    cout << endl;

    for (int i = 0; i < fighters.size(); i++) {
        cout << "║Attack: " << setw(2) << fighters[i].Attack() << setw(9) << "║" << "   ";
    }
}//this just outputs the stats


Fighter& Fighters::pickFighter() {
    int fighterChoice = -1;

    while (fighterChoice < 1 || fighterChoice > fighters.size()) {
        cout << "Please select a fighter by picking 1, 2, or 3\n";
        if ( cin >> fighterChoice ) {
                continue;
        } else {
            cin.clear();
            cin.ignore(256, '\n');
        }
    }
    
    fighterChoice --;

    int selectedHP = fighters[fighterChoice].HP();
    int selectedAttack = fighters[fighterChoice].Attack();

    // Return the chosen fighter's stats
    return fighters[fighterChoice];
}

Fighter::Fighter() {
    ReRoll(); 
}//end of fighter constructor

Fighter::~Fighter() {
}

int Fighter::HP() {
    return _HP;
}

int Fighter::Attack() {
    return _Attack;
}




void Fighter::ReRoll() {
    _HP = rand() % 41 + 10;
    _Attack = rand() % 10 +1; 
}

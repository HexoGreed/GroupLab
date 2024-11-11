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
#include "HatClass.cpp"
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

class Fighter : public Hat {
    public:
        Fighter();
        ~Fighter();

        void takeDamage(int damageTaken, bool defending);
        int Defend(int damage);
        
        void ReRoll();
        void Heal();

        int HP();
        int Attack();
        int baseAttack();
        string name();
 
    private:
        static char names[10][9];
        int _startingHP;
        int _HP;
        int _Attack;   
        int _name;
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

   /* std::cout << "New stats for Fighter " << fighterIndex + 1 << ":\n";
    std::cout << "HP: " << fighters[fighterIndex].HP() << "\n";
    std::cout << "Strength: " << fighters[fighterIndex].Attack() << "\n"; */
}

void Fighters::ReRollAll() {
    for (int i = 0; i < fighters.size(); i++) {
        ReRoll(i);
    }
}

void Fighters::checkFighterStats(){
    for (int i = 0; i < fighters.size(); i++) {  
        cout << "║" << fighters[i].name() << " Stats: ║" << "   ";
    }

    cout << endl;

    for (int i = 0; i < fighters.size(); i++) {
        cout << "║" << "HP: " << setw(2) << fighters[i].HP() << setw(13) << "║" << "   ";
    }

    cout << endl;

    for (int i = 0; i < fighters.size(); i++) {
        cout << "║Attack: " << setw(2) << fighters[i].baseAttack() << setw(9) << "║" << "   ";
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

char Fighter::names[10][9] = {"Jimmybob","Augustus","FightMan","Serenity","Vivienne","Finnegan","Cataleya","Michelle","Shepard","Annalise"};

Fighter::Fighter() {
    ReRoll(); 
}//end of fighter constructor

Fighter::~Fighter() {
}

void Fighter::takeDamage(int damageTaken, bool defending) {
    int actualDamage = defending?Defend(damageTaken):damageTaken;
    _HP -= actualDamage;
    if (_HP < 0){
        _HP = 0;
    }
    // Subtract damage from health here
    // Make sure health doesn't drop below zero
}

int Fighter::Defend(int damage){
    int defense = rand() % 20;
    if (defense == 19){
        cout<<"nat20";
        return 0;
    }
    else if (defense > 9){
        cout<<"1/2 dam";
        return damage/2;
    }
    cout<<"alldam";
    return damage;
}

void Fighter::Heal(){
    _HP = _startingHP;
}

int Fighter::HP() {
    return _HP;
}

int Fighter::Attack() {
    return _Attack + rand() % 6;
}

int Fighter::baseAttack() {
    return _Attack;
}

string Fighter::name(){
    return Fighter::names[_name];
}

void Fighter::ReRoll() {
    _startingHP = _HP = rand() % 41 + 10;
    _Attack = rand() % 10 +1; 
    _name = rand() % 10;
}

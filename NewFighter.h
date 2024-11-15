//============================================================================
// Name        : Fighter.h
// Author      : Hamza, Kazz, with help from Kazz's dad
// Version     : 24/11/15
// Copyright   : >:o
// Description : Fighter Class & Functionality
//============================================================================
#pragma once

#include <iostream>
#include <random>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "HatClass.h"
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


Fighters::Fighters(int numFighters) {
    srand(time(0));
    for ( int i=0; i < numFighters; i++ ) {
        fighters.push_back(Fighter());
    }
}

Fighters::~Fighters() {

}

void Fighters::ReRoll(int fighterIndex) {
    fighters[fighterIndex].ReRoll();
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

char Fighter::names[10][9] = {"Jimmybob","Augustus","FightMan","Serenity","Vivienne","Finnegan","Cataleya","Michelle","Shepards","Annalise"};

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
        return 0; // block all damage
    }
    else if (defense > 9){
        return damage/2; // take half damage
    }
    return damage; // take all damage
}

void Fighter::Heal(){ //resets the fighter HP at the start of a round
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

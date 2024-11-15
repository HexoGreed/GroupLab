//============================================================================
// Name        : Group.cpp
// Author      : Kazz/Hamza/Maribelle/Prem
// Version     : 24/11/15
// Copyright   : >:o
// Description : Fighty Fight Game Main, Group Project
//============================================================================

#include <iostream>
#include <iomanip>
#include <random>

#include "GameLoop.h"
#include "NewFighter.h"
using namespace std;

int fighterChoice;
Fighters PickableFighters;

int main() {
	cout << "Hello! Welcome to Fighty Fight Game! Please choose your Fighter by entering 1, 2, or 3" << endl; 
	
	PickableFighters.checkFighterStats();
	cout << endl;

	cout << "do you wish to reroll? Y OR N\n";
	char choice;
	cin >> choice;
	if (choice == 'Y' || choice == 'y') { 
		PickableFighters.ReRollAll();

		PickableFighters.checkFighterStats();
		cout << endl;
	}
	
	Fighter& fighter = PickableFighters.pickFighter();
	Fighter robot; 

	fighter.chooseHat();

	cout << endl; 
	
	
	cout << setw(31) << "║ Game Start! ║"  << endl; //setw minimum 17
	cout << endl;
	cout << setw(26)<< "You will be fighting " << robot.name() << "!" << endl;
	cout << endl;
	cout << setw(49) << "┌──────────┐" << endl;
	cout << setw(29) << "│ Round 1! │" << endl;
	cout << setw(49) << "└──────────┘" << endl;

	for (int compWins = 0, playerWins = 0, i = 1; compWins <2 && playerWins <2; i++) {		
		if (game(fighter, robot)){
			if (robot.HP() == 0) {
				cout << "They lost all their health! You win!" << endl;
				playerWins++;
			}
			else {
				cout << "You lost all your health! You lost!" << endl;
				compWins++;
			}
			if (compWins == 2){
				cout << robot.name() << " won the tournament!" << endl;
			}
			else if(playerWins == 2){
				/*player.startHat();*/ cout << "You won the tournament!" << endl;
			}
			else {
				cout << endl;
				cout << setw(49) << "┌──────────┐" << endl;
				cout << setw(23) << "│ Round " << i+1 << "! │" << endl;
				cout << setw(49) << "└──────────┘" << endl;
			}
		}
	}
	cout << "Thanks for playing our game!" << endl;
	return 0;
}

//============================================================================
// Name        : Kazz.cpp
// Author      : Kazz
// Version     : 24/11/5
// Copyright   : >:o
// Description : game function
//============================================================================

#include <iostream>
#include <iomanip>
#include "NewFighter.h"
using namespace std;

bool game(int selectedHP, int selectedAttack) { 
    // Testing code //
    int compHealth = 10;
    bool turn = 1;
    int THINGIE = 0;
    // Testing code //

    while (selectedHP > 0 && compHealth > 0) {
       	cout << "╔════════════════════════════════════╗" << endl;

    	while (THINGIE < 2){
			if(turn){
				cout << "║" << setw(25) << "It's your turn!" << setw(14) << "║" << endl;
				cout << "║" << setw(39) << "║" << endl;



				int action;
				cout << "║" << setw(29) << "What do you want to do?" << setw(10) << "║" << endl;
				cout << "║" << setw(30) << "[Attack(1)]   [Defend(2)]" << setw(9) << "║" << endl;
				cin >> action;

				while (action > 2 || action <= 0) { 	// has bug were it will accept letters as numbers
					cout << "║" << setw(6) << "That's not an option, pick again." << setw(10) << "║" << endl;
					cin >> action;
				}
				if (action == 1){
					cout << "║" << "You attacked " << "[OTHER FIGHTER]" << " for " << selectedAttack << " points!"  << setw(2) << "║" << endl;

				}
				else {
				   cout << "║" << setw(29) << "You defended yourself!" << setw(10) << "║" <<  endl;
					// the other turn has to go now to calculate the damage reduction? or something??
				}
				THINGIE++;
			}
			else {
				cout << "║" << setw(30) << "It's the computers turn!" << setw(9) << "║" << endl;
				cout << "║" << setw(39) << "║" << endl;
				int compAction = rand() % 9 + 1;
				//cout << "compAction: " << compAction << endl; //DEBUG
				if(compHealth <= selectedAttack*2){
					//cout << "((LOW  HEALTH))" << endl;       //DEBUG
					if(compAction <= 6){
						cout << "[DEFENDING]" << endl;
					}
					else {  // Theres some copy-pasted code here that 100% should be fixed at somepoint
						cout << "[ATTACKING]" << endl;
						cout << "║" << setw(20) << "They attacked you" << " For " << selectedAttack << " points!" << setw(5) << "║" << endl;
					}
				} else {
					//cout << "((HEALTHY))" << endl;          //DEBUG
					if (compAction <= 8){
						cout << "[ATTACKING]" << endl;
						cout << "║" << setw(20) << "They attacked you" << " For " << selectedAttack << " points!" << setw(5) << "║" << endl;

					}
					else {
						cout << "[DEFENDING]" << endl;
					}
				}

				THINGIE++;
			}

			//damage calcs here

			turn = !turn;
			}
    	compHealth = compHealth - selectedAttack;
    	selectedHP = selectedHP - selectedAttack;
    	cout << "║" << setw(15) << "They have " <<  setw(2) << compHealth << " health left." << setw(9) << "║" << endl;
    	cout << "║" << setw(15) << "You have " << setw(2) << selectedHP << " health left." << setw(9) << "║" << endl;
    	THINGIE = 0;
        cout << "╚════════════════════════════════════╝" << endl;

    }
    
	return turn;	
}

//std::cout << "Damage: " << fighters[fighterIndex][2] << "\n"; 

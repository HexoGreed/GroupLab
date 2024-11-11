//============================================================================
// Name        : GameLoop.cpp
// Author      : Kazz
// Version     : 24/11/11
// Copyright   : >:o
// Description : game function
//============================================================================

#include <iostream>
#include <iomanip>
#include "NewFighter.h"
using namespace std;

int getPlayerAction(Fighter& player) {
	char action;
	cout << "║" << setw(12); player.startHat(); cout << "It's your turn!"; player.endHat(); cout << setw(14) << "║" << endl;
	cout << "║" << setw(39) << "║" << endl;

	cout << "║" << setw(29) << "What do you want to do?" << setw(10) << "║" << endl;
	cout << "║" << setw(29) << "[(A)ttack]   [(D)efend]" << setw(10) << "║" << endl;
	cin >> action;

	while (action != 'A' && action != 'a' && action != 'D' && action != 'd') { 	// has bug were it will accept letters as numbers
		cout << "║" << setw(6) << "That's not an option, pick again." << setw(10) << "║" << endl;
		cin >> action;
	}

	return action == 'A' || action == 'a' ? 1 : 2;
}

bool game(Fighter& player, Fighter& robot) {
	/*bool game(int selectedHP, int selectedAttack) {*/ 
		
	int round = 0;
	
	// Testing code //
    bool turn = 1;
    // Testing code //
	player.Heal();
	robot.Heal();

    while (player.HP() > 0 && robot.HP() > 0) {
		int selectedAttack = player.Attack();
		int compAttack = robot.Attack();
		bool playerDef;
		bool compDef;

       	cout << "╔════════════════════════════════════╗" << endl;
		playerDef = compDef = 0;
    	while (round < 2){		
			if(turn){
				int action = getPlayerAction(player);
				
				if (action == 1){
					cout << "║" << "You attacked " << "[OTHER FIGHTER]" << " for " << selectedAttack << " points!"  << setw(2) << "║" << endl;
				}
				else {
				   cout << "║" << setw(29) << "You defended yourself!" << setw(10) << "║" <<  endl;
					playerDef = 1;
					// the other turn has to go now to calculate the damage reduction? or something??
				}
				round++;
			}
			else {
				cout << "║" << setw(30) << "It's the computers turn!" << setw(9) << "║" << endl;
				cout << "║" << setw(39) << "║" << endl;
				int compAction = rand() % 9 + 1;
				//cout << "compAction: " << compAction << endl; //DEBUG
				if(robot.HP() <= selectedAttack*2){
					//cout << "((LOW  HEALTH))" << endl;       //DEBUG
					if(compAction <= 6){
						cout << "[DEFENDING]" << endl;
						compDef = 1;
					}
					else {  // Theres some copy-pasted code here that 100% should be fixed at somepoint
						cout << "[ATTACKING]" << endl;
						cout << "║" << setw(20) << "They attacked you" << " For " << compAttack << " points!" << setw(5) << "║" << endl;
					}
				} else {
					//cout << "((HEALTHY))" << endl;          //DEBUG
					if (compAction <= 8){
						cout << "[ATTACKING]" << endl;
						cout << "║" << setw(20) << "They attacked you" << " For " << compAttack << " points!" << setw(5) << "║" << endl;

					}
					else {
						cout << "[DEFENDING]" << endl;
						compDef = 1;
					}
				}

				round++;
			}

			turn = !turn;
			}

		if(!playerDef){	
			robot.takeDamage(selectedAttack,compDef);
		}
		if(!compDef){
			player.takeDamage(compAttack,playerDef);
		}

    	cout << "║" << setw(15) << "They have " <<  setw(2) << robot.HP() << " health left." << setw(9) << "║" << endl;
    	cout << "║" << setw(15) << "You have " << setw(2) << player.HP() << " health left." << setw(9) << "║" << endl;
    	round = 0;
        cout << "╚════════════════════════════════════╝" << endl;

    }
    
	return turn;	
}


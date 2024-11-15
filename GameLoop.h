//============================================================================
// Name        : GameLoop.h
// Author      : Kazz
// Version     : 24/11/11
// Copyright   : >:o
// Description : game loop function stuff
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

	while (action != 'A' && action != 'a' && action != 'D' && action != 'd') {
		cout << "║" << setw(34) << "That's not an option, pick again" << setw(5) << "║" << endl;
		cin >> action;
	}

	return action == 'A' || action == 'a' ? 1 : 2;
}

bool game(Fighter& player, Fighter& robot) {

		
	int round = 0;
    bool turn = 1;

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
					cout << "║" ; player.startHat(); cout << "You attacked " << robot.name() << " for " << setw(2) << selectedAttack << " points!"; player.endHat(); cout << setw(3) << "║" << endl;
				}
				else {
				   cout << "║"; player.startHat(); cout << setw(29) << "You defended yourself!"; player.endHat(); cout << setw(10) << "║" <<  endl;
					playerDef = 1;
				}
				round++;
			}
			else {
				cout << "║" << setw(14) << "It's " << robot.name() <<"s turn!" << setw(10) << "║" << endl;
				cout << "║" << setw(39) << "║" << endl;
				int compAction = rand() % 9 + 1;
				if(robot.HP() <= selectedAttack*2){
					if(compAction <= 6){
						cout << "║" << setw(12) << robot.name() << " defended themselves" << setw(7) << "║" << endl;
						compDef = 1;
					}
					else {
						cout << "║" << setw(19) << "They attacked you" << " for " << setw(2) << compAttack << " points!" << setw(5) << "║" << endl;
					}
				} else {
					if (compAction <= 8){
						cout << "║" << setw(19) << "They attacked you" << " for " << setw(2) << compAttack << " points!" << setw(5) << "║" << endl;
					}
					else {
						cout << "║" << setw(12) << robot.name() << " defended themselves" << setw(7) << "║" <<endl;
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

	cout << "║" << setw(39) << "║" << endl;
	cout << "║"; player.startHat(); cout << setw(15) << "You have " << setw(2) << player.HP() << " health left."; player.endHat(); cout << setw(9) << "║" << endl;
    	cout << "║" << setw(15) << "They have " <<  setw(2) << robot.HP() << " health left." << setw(9) << "║" << endl;
    	
    	round = 0;
        cout << "╚════════════════════════════════════╝" << endl;
    }
	return turn;	
}


//============================================================================
// Name        : Group.cpp
// Author      : Kazz/Hamza/Maribelle//Prem
// Version     : 24/11/5
// Copyright   : >:o
// Description : Fighty Fight Game, Group Project
//============================================================================

#include <iostream>
#include <iomanip>
#include "GameLoop.cpp"
using namespace std;

int main() {
	cout << "Hello! Welcome to Fighty Fight Game! Please choose your Fighter by entering 1, 2, or 3" << endl; // prints !!!Hello World!!!
	
	
	cout << "╔════════════════════════════════════╗" << endl;
	cout << "║" << setw(13) << "Fighter 1 " << setw(20) << "Insert stats here" << setw(6) << "║" << endl; //"fighter # " = 10 chars
	cout << "║" << setw(13) << "Fighter 2 " << setw(20) << "Insert stats here" << setw(6) << "║" <<endl;
	cout << "║" << setw(13) << "Fighter 3 " << setw(20) << "Insert stats here" << setw(6) << "║" << endl;
	cout << "╚════════════════════════════════════╝" << endl;
	// Needs stat randomizer

	cout << endl; 

	cout << setw(31) << "║ Game Start! ║"  << endl; //setw minimum 17
	cout << setw(49) << "┌──────────┐" << endl;
	cout << setw(29) << "│ Round 1! │" << endl;
	cout << setw(49) << "└──────────┘" << endl;

	for (int compWins = 0, playerWins = 0, i = 1; compWins <2 && playerWins <2; i++) {		
		if (game()){
			cout << "You lost all your health! You lost!" << endl;
			compWins++;
		}
		else {
			cout << "They lost all their health! You win!" << endl;
			playerWins++;
		}
		if (compWins == 2){
			cout << "[OTHER FIGHTER]" << " Won the tournament!" << endl;
		}
		else if(playerWins == 2){
			cout << "You won the tournament!" << endl;
		}
		else {
			cout << endl;
			cout << setw(49) << "┌──────────┐" << endl;
			cout << setw(23) << "│ Round " << i+1 << "! │" << endl;
			cout << setw(49) << "└──────────┘" << endl;
		}
	}
	
	//Needs turn system
	//Needs to know the stats of the selected fighter
	//Needs enemy fighter

	cout << "Thanks for playing our game!" << endl;
	return 0;
}

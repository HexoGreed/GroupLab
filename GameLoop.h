//============================================================================
// Name        : Kazz.cpp
// Author      : Kazz
// Version     : 24/11/5
// Copyright   : >:o
// Description : game function
//============================================================================

#include <iostream>
using namespace std;

 bool game() { 
    // Testing code //
    int playerHealth = 10;
    int compHealth = 10;
    int damage = 2;
    bool turn = 1;
    // Testing code //

    while (playerHealth > 0 && compHealth > 0) {
        if(turn){
            cout << "╔════════════════════════════════════╗" << endl;
            cout << "║" << setw(25) << "It's your turn!" << setw(14) << "║" << endl;
            cout << "║" << setw(16) << "You have " << setw(2) << playerHealth << " health left." << setw(8) << "║" << endl;
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
                cout << "║" << "You attacked " << "[OTHER FIGHTER]" << " for " << damage << " points!"  << setw(2) << "║" << endl;
                compHealth = compHealth - damage;
            }
            else {
               cout << "║" << setw(6) << "You defended yourself!" << "║" << setw(32) << endl;
                // the other turn has to go now to calculate the damage reduction? or something??
            }
            cout << "╚════════════════════════════════════╝" << endl;
            cout << endl;
        }
        else {
            cout << "╔════════════════════════════════════╗" << endl;
            cout << "║" << setw(30) << "It's the computers turn!" << setw(9) << "║" << endl;
            cout << "║" << setw(15) << "They have " <<  setw(2) << compHealth << " health left" << setw(10) << "║" << endl;
            cout << "║" << setw(39) << "║" << endl;
            int compAction = rand() % 9 + 1;
            //cout << "compAction: " << compAction << endl; //DEBUG
            if(compHealth <= damage*2){
                //cout << "((LOW  HEALTH))" << endl;       //DEBUG  
                if(compAction <= 6){
                    cout << "[DEFENDING]" << endl;
                }
                else {  // Theres some copy-pasted code here that 100% should be fixed at somepoint
                    cout << "[ATTACKING]" << endl;
                    cout << "║" << setw(20) << "They attacked you" << " For " << damage << " points!" << setw(5) << "║" << endl;
                    playerHealth = playerHealth - damage;
                }
            } else {
                //cout << "((HEALTHY))" << endl;          //DEBUG
                if (compAction <= 8){
                    cout << "[ATTACKING]" << endl;
                    cout << "║" << setw(20) << "They attacked you" << " For " << damage << " points!" << setw(5) << "║" << endl;
                    playerHealth = playerHealth - damage;
                }
                else {
                    cout << "[DEFENDING]" << endl; 
                }
            }
            
            cout << "╚════════════════════════════════════╝" << endl;
            
            cout << endl;
        }
        turn = !turn;
    }
    
	return turn;	
}
//std::cout << "Damage: " << fighters[fighterIndex][2] << "\n"; 

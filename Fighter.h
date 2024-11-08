#pragma once
//makes sure its only included once;
#include <iostream>
#include <random>
#include <vector>
#include <utility>
//this is needed for the pair return functon
#include "PlayerClass.h"

using namespace std;

class Fighter {

    
private:
    vector<vector<int>> fighters; 
    //2d array, stores stats
   
public:
    //this is a constructor

    Fighter() {
        fighters = vector<vector<int>>(3, vector<int>(2));
        //3 fighters 2 states each;


        srand(time(0)); //seeding the randomness so its random every time


        for (int i = 0; i < fighters.size(); i++) {
            for (int j = 0; j < fighters[i].size(); j++) {
                if (j == 0) {
                    fighters[i][j] = rand() % 41 + 10;
                    //hp is random 10-50
                }
                else if (j == 1) {
                    fighters[i][j] = rand() % 10 + 1;
                    //attack is random 1-10
                }
            }
        }

    }//end of fighter constructor

    void checkFighterStats(){
        for (int i = 0; i < fighters.size(); i++) {
            std::cout << "Figher " << i + 1 << " Stats: \n";
            std::cout << "HP: " << fighters[i][0] << " \nAttack: " << fighters[i][1] << "\n\n";
        }
    }//this just outputs the stats




    
   
    

    void ReRoll(int fighterIndex) {
        if (fighterIndex < 0 || fighterIndex >= fighters.size()) {
            std::cout << "Invalid Index";
            return;
        }

        for (int i = 0; i < fighters[fighterIndex].size(); i++) {
            if (i == 0) { // If it's the HP stat
                fighters[fighterIndex][i] = rand() % 41 + 10;
            }
            else if (i == 1) { // If it's the Strength stat
                fighters[fighterIndex][i] = rand() % 10 + 1;
            }
        }

        std::cout << "New stats for Fighter " << fighterIndex + 1 << ":\n";
        std::cout << "HP: " << fighters[fighterIndex][0] << "\n";
        std::cout << "Strength: " << fighters[fighterIndex][1] << "\n";
    }


    //PAIR RETURNS TWO INTS, cps lck
    std::pair<int, int> pickFighter() {
        cout << "Please select a fighter by picking 1, 2, or 3\n";
        int fighterChoice;
        cin >> fighterChoice;

        while (fighterChoice < 1 || fighterChoice > 3) { // Ensure valid input
            cout << "Invalid choice. Please select a valid fighter number (1, 2, or 3): ";
            cin >> fighterChoice;
        }
        fighterChoice -= 1;
        //vectors start from 0-2; making sue the input is actually valid

        int selectedHP = fighters[fighterChoice][0];
        int selectedAttack = fighters[fighterChoice][1];

        // Return the chosen fighter's stats
        return std::make_pair(selectedHP, selectedAttack);
        //Constructs a pair object with its first element set to x and its second element set to y.
    }

};


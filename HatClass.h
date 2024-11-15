//============================================================================
// Name        : Group.cpp
// Author      : Maribelle/Kazz
// Version     : 24/11/15
// Copyright   : >:o
// Description : Hat Class
//============================================================================
#pragma once

#include <iostream>
#include <string>
//#include all files at the end
using namespace std;

class Hat {

private:
    int HatChoice;

public:
    Hat();
    ~Hat();
    int hatCode();
    void chooseHat();
    void startHat();
    void endHat();
};

Hat::Hat(){
}

Hat::~Hat(){
}

void Hat::chooseHat() {    
    cout << "Enter the number of the hat you want to wear:" << endl;

    cout << "1. Top Hat" << endl;
    cout << "2. Viking Helmet" << endl;
    cout << "3. Cowboy Hat" << endl; 
    cout << "4. Baseball Cap" << endl; 
    cout << "5. Party Hat" << endl; 
    cout << "6. Chef Hat" << endl; 
    HatChoice = 0;
    
    while(HatChoice < 1 || HatChoice > 6){
        if (cin >> HatChoice) {
            if (HatChoice == 1) {
                cout << "You chose the Top Hat!" << endl; 
            } else if (HatChoice == 2) {
                cout << "You chose the Viking Helmet!" << endl;
            } else if (HatChoice == 3) {
                cout << "You chose the Cowboy Hat!" << endl;
            } else if (HatChoice == 4) {
                cout << "You chose the Baseball Cap!" << endl;
            } else if (HatChoice == 5) {
                cout << "You chose the Party Hat!" << endl;
            } else if (HatChoice == 6) {
                cout << "You chose the Chef Hat!" << endl;
            }
            else {
                cout << "Invalid choice, please enter 1, 2, or 3:" << endl;
            } 
        }
        else {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Invalid choice, please enter 1, 2, or 3:" << endl;
        } 
    }
}

void Hat::startHat() {
    cout << "\033[" << hatCode() << "m";
}

void Hat::endHat() {
    cout << "\033[0m";
}

int Hat::hatCode() {
   return 30+HatChoice;
}

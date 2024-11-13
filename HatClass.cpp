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

	 //int HatChoice
		//Prompts for user
	    cout << "Enter the number of the hat you want to wear:" << endl;
		cout << "1. Cowboy Hat" << endl;
		cout << "2. Party Hat" << endl;
		cout << "3. Chef Hat" << endl;
		cout << "Enter your choice 1, 2, or 3: ";
		cin >> HatChoice;


    cin.clear();
    cin.ignore(256, '\n');
    while (1){
    	 // getline(cin, HatChoice);
		if (HatChoice == 1) {
			cout << "You chose the Cowboy Hat!" << endl;
			break;
		} else if (HatChoice == 2) {
			cout << "You chose the Party Hat!" << endl;
			break;
		} else if (HatChoice == 3) {
			cout << "You chose the Chef Hat!" << endl;
			break;
		} else {
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
    if(HatChoice == 1){ //cowboy
        return 33;
    }
    else if(HatChoice == 2){ //party
        return 35;
    }
    else if (HatChoice == 3){ //chef
        return 36;
    }
    return 0;
}

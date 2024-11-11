#include <iostream>
#include <string>
//#include all files at the end
using namespace std;

class Hat {

private:
    string HatChoice;

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
    cout << "Enter the name of the hat you want to wear (Cowboy Hat, Party Hat, Chef Hat): ";
    
    cin.clear();
    cin.ignore(256, '\n');
    while (1){
        getline(cin, HatChoice); 
        if (HatChoice == "cowboy hat" or HatChoice == "party hat" or HatChoice == "chef hat") {
            cout << "You are wearing a " << HatChoice << "!" << endl;
            return;
        } else {
            cout << "Invalid choice! Please enter either Cowboy Hat, Party Hat, or Chef Hat." << endl;
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
    if(HatChoice == "cowboy hat"){
        return 33;
    }
    else if(HatChoice == "party hat"){
        return 35;
    }
    else if (HatChoice == "chef hat"){
        return 36;
    }
    return 0;
}

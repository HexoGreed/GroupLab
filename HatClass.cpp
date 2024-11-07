#include <iostream>
#include <string>
//#include all files at the end
using namespace std;

class Hat {

private:
    string HatChoice;

public:

    void chooseHat() {
        cout << "Enter the name of the hat you want to wear (Cowboy Hat, Party Hat, Chef Hat): ";
        getline(cin, HatChoice);

        if (HatChoice == "Cowboy Hat" or HatChoice == "Party Hat" or HatChoice == "Chef Hat") {
            cout << "You are wearing a " << HatChoice << "!" << endl;
        } else {
            cout << "Invalid choice! Please enter either Cowboy Hat, Party Hat, or Chef Hat." << endl;
        }
    }
};

/*
int main() {
    Hat hat; //put this in main at the end
    hat.chooseHat(); //put this in main at the end

    return 0;
}
*/

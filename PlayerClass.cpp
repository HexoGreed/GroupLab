#pragma once
//makes sure its only included once
#include "Fighter.h"
using namespace std;

class PLayer {
private:
	int hp;
	int attack;

public:
	void setPlayerStats(const std::pair<int, int>& fighterStats) {
		//the and is a refrence because thats how it works, (I was bashing my head against a wall :3 )
		hp = fighterStats.first;
		attack = fighterStats.second;
	}
    
	void displayPlayerStats() {
		cout << "Player Stats:\n";
		cout << "HP: " << hp << "\n";
		cout << "Attack: " << attack << "\n";
	}

	void updatePlayerHP(int enemyAttack) {
		hp -= enemyAttack;
	}
	



};




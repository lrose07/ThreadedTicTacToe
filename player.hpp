#pragma once
using namespace std;

class Player {
public:
	Player();
	void run();
	bool getPlayerTurnStatus();
	~Player();
private:
	bool playerTurn;
};
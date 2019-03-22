#pragma once
#include <vector>
#include <mutex>
using namespace std;

class Board {
public:
	Board();
	vector<int> getBoard();
	bool tryToMove();
	void moveMade();
	~Board();

	
private:
	mutex boardLock;
	vector<int> boardArray;
};
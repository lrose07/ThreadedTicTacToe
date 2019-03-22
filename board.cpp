#include "board.hpp"
#include <vector>
#include <mutex>
using namespace std;

Board::Board() {
	for (int i = 1; i <= 9; i++) {
		boardArray.push_back(0);
	}
}

bool Board::tryToMove() {
	return boardLock.try_lock();
}

void Board::moveMade() {
	boardLock.unlock();
}

vector<int> Board::getBoard() {
	return boardArray;
}

Board::~Board() {}
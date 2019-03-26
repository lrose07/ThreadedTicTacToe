#include <iostream>
using namespace std;

char boardGrid[10] = {'z','1','2','3','4','5','6','7','8','9'};

int hasSomeoneWon() {
    if ((boardGrid[1] == boardGrid[2] && boardGrid[2] == boardGrid[3]) ||
    	(boardGrid[4] == boardGrid[5] && boardGrid[5] == boardGrid[6]) ||
    	(boardGrid[7] == boardGrid[8] && boardGrid[8] == boardGrid[9]) ||
    	(boardGrid[1] == boardGrid[4] && boardGrid[4] == boardGrid[7]) ||
    	(boardGrid[2] == boardGrid[5] && boardGrid[5] == boardGrid[8]) ||
    	(boardGrid[3] == boardGrid[6] && boardGrid[6] == boardGrid[9]) ||
    	(boardGrid[1] == boardGrid[5] && boardGrid[5] == boardGrid[9]) ||
    	(boardGrid[3] == boardGrid[5] && boardGrid[5] == boardGrid[7])) {
    		return 1;
    	}
    else if (boardGrid[1] != '1' && boardGrid[2] != '2' && boardGrid[3] != '3' 
                    && boardGrid[4] != '4' && boardGrid[5] != '5' && boardGrid[6] != '6' 
                  && boardGrid[7] != '7' && boardGrid[8] != '8' && boardGrid[9] != '9')
        return 0;
    else
        return -1;
}

void drawBoard() {
    cout << endl << endl << "Let's Play Tic Tac Toe!" << endl << endl;
    cout << " " << boardGrid[1] << " | " << boardGrid[2] << " | " << boardGrid[3] << endl;
    cout << "---+---+---" << endl;
    cout << " " << boardGrid[4] << " | " << boardGrid[5] << " | " << boardGrid[6] << endl;
    cout << "---+---+---" << endl;
    cout << " " << boardGrid[7] << " | " << boardGrid[8] << " | " << boardGrid[9] << endl;
}

char getComputerMove() {
	int tempRandom = (rand() % 9) + 1;
	return tempRandom;
}

int main() {
	srand(time(NULL));
	int player = 1, anyoneWonYet, computerMove;
    char symbol;

    do {
        drawBoard();
        player = (player % 2) ? 1 : 2;

        do {
        	computerMove = getComputerMove();
        } while (boardGrid[computerMove] == 'X' || boardGrid[computerMove] == 'O');

        symbol=(player == 1) ? 'X' : 'O';

        if (computerMove == 1 && boardGrid[1] == '1') {
        	boardGrid[1] = symbol;
        }
        else if (computerMove == 2 && boardGrid[2] == '2') {
        	boardGrid[2] = symbol;
        }
        else if (computerMove == 3 && boardGrid[3] == '3') {
        	boardGrid[3] = symbol;
        }
        else if (computerMove == 4 && boardGrid[4] == '4') {
        	boardGrid[4] = symbol;
        }
        else if (computerMove == 5 && boardGrid[5] == '5') {
        	boardGrid[5] = symbol;
        }
        else if (computerMove == 6 && boardGrid[6] == '6') {
        	boardGrid[6] = symbol;
        }
        else if (computerMove == 7 && boardGrid[7] == '7') {
        	boardGrid[7] = symbol;
        }
        else if (computerMove == 8 && boardGrid[8] == '8') {
        	boardGrid[8] = symbol;
        }
        else if (computerMove == 9 && boardGrid[9] == '9') {
        	boardGrid[9] = symbol;
        }

        anyoneWonYet = hasSomeoneWon();

        player++;
    } while(anyoneWonYet == -1);

    drawBoard();

    if(anyoneWonYet == 1) {
    	cout << "Player " << --player << " win ";
    }
    else {
    	cout << "No one wins!";
    }

    cin.ignore();
    cin.get();
    return 0;
}
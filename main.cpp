#include <iostream>
#include <thread>
using namespace std;

/*
 * Lauren Rose
 * ITEC 371
 * Department of Information Technology
 * Radford University
 *
 * This program uses a tic-tac-toe game to demonstrate
 * the use of threads.
 *
 * v0.1
 */

//\
Global vars
char boardGrid[10] = {'z','1','2','3','4','5','6','7','8','9'};

pthread_mutex_t mutex;
int mutexInt = pthread_mutex_init(&mutex, NULL);

bool isPlayerOneTurn = false;
bool isPlayerTwoTurn = false;
int player = 1;
bool gameWon = false;
int playerTurn = 0;
int lastToMove = 2;
char symbol;
int winner;

//\
Formard declarations
void drawBoard();
int hasSomeoneWon();
char getComputerMove();
void drawBoard();
void processWinner();
void processDraw();

//\
Thread function for player 1
void* playerOneTurn(void*) {
    while(!gameWon) {
        pthread_mutex_lock(&mutex);
        if(isPlayerOneTurn) {
            cout << endl << "Player one moving" << endl;
            int computerMove = getComputerMove();
            symbol = 'X';
            boardGrid[computerMove] = symbol;
            lastToMove = 1;
            isPlayerOneTurn = false;
            playerTurn = 0;
        }

        pthread_mutex_unlock(&mutex);
    }
}

//\
Thread function for player 2
void* playerTwoTurn(void*) {
    while(!gameWon) {
        pthread_mutex_lock(&mutex);
        if (isPlayerTwoTurn) {
            cout << endl << "Player two moving" << endl;
            int computerMove = getComputerMove();
            symbol = 'O';
            boardGrid[computerMove] = symbol;
            lastToMove = 2;
            isPlayerTwoTurn = false;
            playerTurn = 0;
        }
 
        pthread_mutex_unlock(&mutex);
    }
}

//\
Thread function for the main game
void* game(void*) {

    cout << "Player 1 thread created" << endl;
    cout << "Player 2 thread created" << endl;

    pthread_t p1Thread;
    pthread_create(&p1Thread, NULL, &playerOneTurn, NULL);
    pthread_t p2Thread;
    pthread_create(&p2Thread, NULL, &playerTwoTurn, NULL);

    while(!gameWon) {
        pthread_mutex_lock(&mutex);

        if (playerTurn == 0) {
            cout << endl << "game thread checking stuff" << endl;
            drawBoard();
            if (hasSomeoneWon() == 1) {
                processWinner();
                break;
            } else if (hasSomeoneWon() == 0) {
                processDraw();
                break;
            } else {
                if (lastToMove == 1) {
                    playerTurn = 2;
                    isPlayerTwoTurn = true;
                } else if (lastToMove == 2) {
                    playerTurn = 1;
                    isPlayerOneTurn = true;
                }
            }
        } 
        pthread_mutex_unlock(&mutex);
    }

    drawBoard();

    // pthread_join(p1Thread, NULL);
    // pthread_join(p2Thread, NULL);
}

//\
Outputs the winner based on who was the last to \
move when the win condition was met
void processWinner() {
    if (lastToMove == 1) {
        winner = 1;
    } else if (lastToMove == 2) {
        winner = 2;
    }
    cout << endl << "Player " << winner << " win " << endl;
}

//\
Outputs when all spaces have been filled and \
neither player satisfies the win condition
void processDraw() {
    cout << endl << "No one wins!" << endl;
}

//\
Checks to see if the board contains a win condition
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
            gameWon = true;
    	}
    else if (boardGrid[1] != '1' && boardGrid[2] != '2' && boardGrid[3] != '3' 
                    && boardGrid[4] != '4' && boardGrid[5] != '5' && boardGrid[6] != '6' 
                  && boardGrid[7] != '7' && boardGrid[8] != '8' && boardGrid[9] != '9')
        return 0;
    else
        return -1;
}

//\
Draws the board to the std out
void drawBoard() {
    cout << endl;
    cout << " " << boardGrid[1] << " | " << boardGrid[2] << " | " << boardGrid[3] << endl;
    cout << "---+---+---" << endl;
    cout << " " << boardGrid[4] << " | " << boardGrid[5] << " | " << boardGrid[6] << endl;
    cout << "---+---+---" << endl;
    cout << " " << boardGrid[7] << " | " << boardGrid[8] << " | " << boardGrid[9] << endl;
}

//\
Generates random numbers from 1-9 and returns the first \
one that is an unoccupied board space
char getComputerMove() {
    int tempRandom;
    do {
        tempRandom = (rand() % 9) + 1;
    } while (boardGrid[tempRandom] == 'X' || boardGrid[tempRandom] == 'O');
	return tempRandom;
}

//\
Main program function, kicks off the main game thread
int main() {
    srand(time(NULL));

    cout << "Main thread created" << endl;
	
    pthread_t mainGameThread;
    pthread_create(&mainGameThread, NULL, &game, NULL);

    pthread_join(mainGameThread, NULL);

    cout << "All threads destroyed" << endl;

    return 0;
}
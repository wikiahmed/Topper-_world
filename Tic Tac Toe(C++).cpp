#include <iostream>
#include <vector>

using namespace std;


void drawBoard(const vector<char>& board) {
    cout << " " << board[0] << " | " << board[1] << " | " << board[2] << endl;
    cout << "---+---+---" << endl;
    cout << " " << board[3] << " | " << board[4] << " | " << board[5] << endl;
    cout << "---+---+---" << endl;
    cout << " " << board[6] << " | " << board[7] << " | " << board[8] << endl;
}


bool checkWin(const vector<char>& board, char player) {
 
    for (int i = 0; i < 9; i += 3) {
        if ((board[i] == player) && (board[i + 1] == player) && (board[i + 2] == player))
            return true;
    }


    for (int i = 0; i < 3; i++) {
        if ((board[i] == player) && (board[i + 3] == player) && (board[i + 6] == player))
            return true;
    }


    if ((board[0] == player) && (board[4] == player) && (board[8] == player))
        return true;

    if ((board[2] == player) && (board[4] == player) && (board[6] == player))
        return true;

    return false;
}

void playGame() {
    vector<char> board(9, ' ');

    char currentPlayer = 'X';
    int moves = 0;

    do {
        while (moves < 9) {
            drawBoard(board);

            cout << "Player " << currentPlayer << ", enter your move (1-9): ";
            int move;
            cin >> move;

            if (board[move - 1] == ' ') {
                board[move - 1] = currentPlayer;
                moves++;

                if (checkWin(board, currentPlayer)) {
                    drawBoard(board);
                    cout << "Player " << currentPlayer << " wins!" << endl;
                    break;
                }

                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            } else {
                cout << "Invalid move. Try again." << endl;
            }
        }

        if (moves == 9) {
            drawBoard(board);
            cout << "It's a draw!" << endl;
        }

        cout << "Do you want to play again? (Y/N): ";
        char choice;
        cin >> choice;

        if (choice == 'n') {
            break;
        }if(choice=='y') {
            board = vector<char>(9, ' ');
            currentPlayer = 'X';
            moves = 0;
            }
    } while (true);
}

int main() {
    cout << "Tic Tac Toe Game" << endl;
     cout << " " << endl;
    playGame();
    return 0;
}
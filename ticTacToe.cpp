#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;
vector<char> board = { '-', '-', '-',
                            '-', '-', '-',
                            '-', '-', '-' };
char currentPlayer = 'X';
char winner = '\0';
bool gameRunning = true;

void printBoard(const vector<char>& board) {
    cout << board[0] << " | " << board[1] << " | " << board[2] << endl;
    cout << "---------" << endl;
    cout << board[3] << " | " << board[4] << " | " << board[5] << endl;
    cout << "---------" << endl;
    cout << board[6] << " | " << board[7] << " | " << board[8] << endl;
}

void playerInput(vector<char>& board) {
    int inp;
    cout << "Select a spot 1-9: ";
    cin >> inp;
    if (inp >= 1 && inp <= 9 && board[inp - 1] == '-') {
        board[inp - 1] = currentPlayer;
    }
    else {
        cout << "Oops invalid input" << endl;
    }
}

bool checkHorizontal(const vector<char>& board) {
    if (board[0] == board[1] && board[1] == board[2] && board[0] != '-') {
        winner = board[0];
        return true;
    }
    else if (board[3] == board[4] && board[4] == board[5] && board[3] != '-') {
        winner = board[3];
        return true;
    }
    else if (board[6] == board[7] && board[7] == board[8] && board[6] != '-') {
        winner = board[6];
        return true;
    }
    return false;
}

bool checkVertical(const vector<char>& board) {
    if (board[0] == board[3] && board[3] == board[6] && board[0] != '-') {
        winner = board[0];
        return true;
    }
    else if (board[1] == board[4] && board[4] == board[7] && board[1] != '-') {
        winner = board[1];
        return true;
    }
    else if (board[2] == board[5] && board[5] == board[8] && board[2] != '-') {
        winner = board[2];
        return true;
    }
    return false;
}

bool checkDiagonal(const vector<char>& board) {
    if (board[0] == board[4] && board[4] == board[8] && board[0] != '-') {
        winner = board[0];
        return true;
    }
    else if (board[2] == board[4] && board[4] == board[6] && board[2] != '-') {
        winner = board[2];
        return true;
    }
    return false;
}

bool checkTie(const vector<char>& board) {
    for (char spot : board) {
        if (spot == '-') {
            return false;
        }
    }
    return true;
}

void switchPlayer() {
    if (currentPlayer == 'X') {
        currentPlayer = 'O';
    }
    else {
        currentPlayer = 'X';
    }
}

void checkWin(const vector<char>& board) {
    if (checkDiagonal(board) || checkHorizontal(board) || checkVertical(board)) {
        cout << "The Winner is " << winner << "!" << endl;
        gameRunning = false;
    }
}

void computer(vector<char>& board) {
    while (currentPlayer == 'O') {
        int position = rand() % 9;
        if (board[position] == '-') {
            board[position] = 'O';
            switchPlayer();
        }
    }
}

int main() {
    srand(time(nullptr));
    
    while (gameRunning) {
        printBoard(board);
        playerInput(board);
        checkWin(board);
        if (checkTie(board)) {
            printBoard(board);
            cout << "It's a tie boi" << endl;
            gameRunning = false;
            break;
        }
        switchPlayer();
        computer(board);
        checkWin(board);
        if (checkTie(board)) {
            printBoard(board);
            cout << "It's a tie boi" << endl;
            gameRunning = false;
        }
    }

    return 0;
}

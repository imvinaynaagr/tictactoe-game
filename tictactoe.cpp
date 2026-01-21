#include <iostream>
using namespace std;

char board[3][3] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};

char turn = 'X';
bool draw = false;

// Function to display the board
void displayBoard() {
    cout << "\nTIC TAC TOE GAME\n\n";
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << " " << board[i][j] << " ";
            if(j < 2) cout << "|";
        }
        if(i < 2) cout << "\n---|---|---\n";
    }
    cout << "\n";
}

// Function to take player input
void playerTurn() {
    int choice;
    cout << "\nPlayer " << turn << ", enter a number: ";
    cin >> choice;

    int row, col;

    if(choice == 1) { row = 0; col = 0; }
    else if(choice == 2) { row = 0; col = 1; }
    else if(choice == 3) { row = 0; col = 2; }
    else if(choice == 4) { row = 1; col = 0; }
    else if(choice == 5) { row = 1; col = 1; }
    else if(choice == 6) { row = 1; col = 2; }
    else if(choice == 7) { row = 2; col = 0; }
    else if(choice == 8) { row = 2; col = 1; }
    else if(choice == 9) { row = 2; col = 2; }
    else {
        cout << "Invalid choice! Try again.\n";
        playerTurn();
        return;
    }

    if(board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = turn;
        turn = (turn == 'X') ? 'O' : 'X';
    } else {
        cout << "Cell already taken! Try again.\n";
        playerTurn();
    }
}

// Function to check game status
bool gameOver() {
    // Check rows and columns
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2])
            return false;
        if(board[0][i] == board[1][i] && board[0][i] == board[2][i])
            return false;
    }

    // Check diagonals
    if(board[0][0] == board[1][1] && board[0][0] == board[2][2])
        return false;
    if(board[0][2] == board[1][1] && board[0][2] == board[2][0])
        return false;

    // Check draw
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(board[i][j] != 'X' && board[i][j] != 'O')
                return true;

    draw = true;
    return false;
}

// Main function
int main() {
    while(gameOver()) {
        displayBoard();
        playerTurn();
    }

    displayBoard();

    if(draw)
        cout << "Game Draw!\n";
    else
        cout << "Player " << (turn == 'X' ? 'O' : 'X') << " wins!\n";

    return 0;
}

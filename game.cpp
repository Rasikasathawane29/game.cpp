#include <stdio.h>

// Function to print the current state of the game board
void print_board(char board[][3]) {
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

// Function to check if a player has won the game
int check_win(char board[][3], char player) {
    // Check horizontal rows
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }
    // Check vertical columns
    for(int i = 0; i < 3; i++) {
        if(board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return 1;
        }
    }
    // Check diagonals
    if(board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    if(board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }
    return 0;
}

int main() {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char player = 'X';
    int row, col;
    int moves_left = 9;

    printf("Let's play Tic Tac Toe!\n");

    // Loop until the game is won or tied
    while(1) {
        printf("Player %c's turn\n", player);
        print_board(board);
        printf("Enter row and column (e.g. 1 2 3 4 5 6 7 8 9):");   
	    scanf("%d %d",&row,&col);

        // Check if the position is valid and not already taken
        if(row < 1 || row > 3 || col < 1 || col > 3) {
            printf("Invalid position, please try again.\n");
            continue;
        }
        if(board[row-1][col-1] != ' ') {
            printf("Position already taken, please try again.\n");
            continue;
        }

        // Place the player's marker on the board
        board[row-1][col-1] = player;

        // Check if the player has won
        if(check_win(board, player)) {
            printf("Player %c wins!\n", player);
            break;
        }

        // Switch to the other player
        player = (player == 'X') ? 'O' : 'X';

        // Decrement the moves left counter
        moves_left--;

        // Check if the game is tied
        if(moves_left == 0) {
            printf("Tie game!\n");
            break;
    }
};
    return 0;
};


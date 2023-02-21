#include <stdio.h>
#include <stdlib.h>

char** innitBoard();
void printBoard(char **board);
char rowColumnToBlock(char row, char column);
char searchRow(char **board, char, char);
char searchColumn(char **board, char, char);
char searchBlock(char **board, char, char, char);

int main() {
    char **board = innitBoard();
    printBoard(board);
    return 0;
}

char** innitBoard() {
    char **board = malloc(sizeof(char*) * 9);
    char array[9][9] = {{0, 1, 9,    0, 0, 2,    0, 0, 0},
                        {4, 7, 0,    6, 9, 0,    0, 0, 1},
                        {0, 0, 0,    4, 0, 0,    0, 9, 0},

                        {8, 9, 4,    5, 0, 7,    0, 0, 0},    
                        {0, 0, 0,    0, 0, 0,    0, 0, 0},
                        {0, 0, 0,    2, 0, 1,    9, 5, 8},

                        {0, 5, 0,    0, 0, 6,    0, 0, 0},
                        {6, 0, 0,    0, 2, 8,    0, 7, 9},
                        {0, 0, 0,    1, 0, 0,    8, 6, 0}};

    for (int row = 0; row < 9; row++) {
        board[row] = malloc(sizeof(char) * 9);
        for (int column = 0; column < 9; column++)
            board[row][column] = array[row][column];
    }
    
    return board;
}

void printBoard(char **board) {
    for (int column = 0; column < 25; column++) printf("-");
    printf("\n");
    for (int row = 0; row < 9; row++) {
        printf("| ");
        for (int column = 0; column < 9; column++) {
            if ((column + 1) % 3 == 0) {
                printf("%d | ", board[row][column]);
                continue;
            }
            printf("%d ", board[row][column]);
        }
        if ((row + 1) % 3 == 0) {
            printf("\n");
            for (int column = 0; column < 25; column++) printf("-");
        }
        printf("\n");
    }
}

char searchRow(char **board, char row, char number) {
    for (int column = 0; column < 9; column++) {
        if (board[row][column] == number) return 1;
    }
    return 0;
}

char searchColumn(char **board, char column, char number) {
    for (int row = 0; row < 9; row++) {
        if (board[row][column] == number) return 1;
    }
    return 0;
}

char rowColumnToBlock(char row, char column) {
    return ((row / 3) * 3 + column / 3);
}

char searchBlock(char **board, char row, char column, char number) {
    char block = rowColumnToBlock(row, column);
    printf("\n%d", block);
    char rowStart = (block / 3) * 3, columnStart = (block % 3) * 3;
    printf("\n%d;%d", rowStart, columnStart);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[rowStart + i][columnStart + j] == number) return 1;
        }
    }
    return 0;
}
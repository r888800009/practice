#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM_OF_QUEEN 8
#define SIZE 8

typedef int Pos;

void display(Pos queens[NUM_OF_QUEEN], int size)
{
    // print
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            if (queens[y] == x)
                printf("Q");
            else
                printf("_");
        }

        printf("\n");
    }
}

bool canPut(Pos queens[NUM_OF_QUEEN], Pos newQueen, int numOfOnBoard)
{
    for (int y = 0; y < numOfOnBoard; y++) {
        Pos relative = newQueen - queens[y];

        // vertical line or horizontal line or some pos
        if (relative == 0 || numOfOnBoard - y == 0)
            return false;

        // forward slash or back slash
        if (abs(relative) == abs(numOfOnBoard - y))
            return false;
    }

    return true;
}

bool backtracking(Pos *queens, int num_of_queens, int board_size, int numOfOnBoard)
{
    // every rescursive we solve one row
    // so this rescursive will chose one column
    if (numOfOnBoard >= num_of_queens) {
        // basecase
        return true;
    } else {
        // chose one column
        for (int x = 0; x < board_size; x++) {
            if (canPut(queens, x, numOfOnBoard)) {
                queens[numOfOnBoard] = x;

                // next row
                if (backtracking(queens, num_of_queens, board_size, numOfOnBoard + 1))
                    return true;
            }
        }

        return false;
    }
}

int main()
{
    Pos queens[NUM_OF_QUEEN];
    int i = backtracking(queens, NUM_OF_QUEEN, SIZE, 0);
    printf("%d\n", i);
    display(queens, SIZE);
    return 0;
}

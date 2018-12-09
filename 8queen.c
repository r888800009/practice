#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM_OF_QUEEN 8
#define SIZE 8

typedef struct Pos {
    int x, y;
} Pos;

void swap(Pos *a, Pos *b)
{
    Pos tmp = *a;
    *a = *b;
    *b = tmp;
}

void display(Pos queens[NUM_OF_QUEEN], int size)
{
    // sory by y dec
    for (int sortedPos; sortedPos < size; sortedPos++) {
        for (int curPos = size - 1; curPos > 0; curPos--)
            if (queens[curPos - 1].y > queens[curPos].y)
                swap(&queens[curPos - 1], &queens[curPos]);
    }

    // print
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            if (queens[y].x == x)
                printf("Q");
            else
                printf("_");
        }

        printf("\n");
    }
}

bool canPut(Pos queens[NUM_OF_QUEEN], Pos newQueen, int numOfOnBoard)
{
    for (int i = 0; i < numOfOnBoard; i++) {
        Pos relative = {newQueen.x - queens[i].x, newQueen.y - queens[i].y};

        // vertical line or horizontal line or some pos
        if (relative.x == 0 || relative.y == 0)
            return false;

        // forward slash or back slash
        if (abs(relative.x) == abs(relative.y))
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
            Pos newQueen = {x, numOfOnBoard};
            if (canPut(queens, newQueen, numOfOnBoard)) {
                queens[numOfOnBoard] = newQueen;

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

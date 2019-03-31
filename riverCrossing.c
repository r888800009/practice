#include <stdio.h>

// [man, dog, sheep, vegetable]
char impassable[6] = {0b0011, 0b0110, 0b0111, 0b1000, 0b1001, 0b1100};

char stack[15];
int top = 0;

int isPassable(char status) {
    // check repeating
    for (int i = 0; i < top; i++)
        if (stack[i] == status) return 0;

    // check impassable
    for (int i = 0; i < 6; i++)
        if (impassable[i] == status) return 0;

    return 1;
}

int moveCounter(char cur, char next) {
    int result = 0;

    // get diff
    cur ^= next;

    // count diff
    while (cur > 0) {
        if (cur & 1) result++;

        cur >>= 1;
    }

    return result;
}

void river(char status) {
    stack[top] = status;
    top++;

    // basecase is status to 0b0000
    if (status == 0b0000) {
        // print stack
        for (int i = 0; i < top - 1; i++) printf("%d => ", stack[i]);

        printf("%d\n", stack[top - 1]);
    } else {
        for (char i = 0; i <= 15; i++) {
            // man on the boat toggle
            if ((status & 0b1000) != (i & 0b1000)) {
                // only allowed change less than or equal to 2 bit
                if (moveCounter(status, i) <= 2) {
                    // not repeating and impassable
                    if (isPassable(i)) river(i);
                }
            }
        }
    }

    top--;
}

int main() {
    river(0b1111);
    return 0;
}

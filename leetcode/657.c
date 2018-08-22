#include <string.h>
bool judgeCircle(char *moves) {
    int x = 0, y = 0, len = strlen(moves);
    
    for (int i = 0; i < len; i++) {
        switch (moves[i]) {
            case 'R':
                x++;
                break;
            case 'L':
                x--;
                break;
            case 'U':
                y--;
                break;
            case 'D':
                y++;
        }        
    }
    if (x == y && y == 0)
        return true;
    else 
        return false;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define buffer_size 128
#define hashsize 256

typedef struct hashtable {
    char str[buffer_size];
    int isAC;
    int firstAC;
} table;

int nonKillAC = 0, killAC = 0;

int hash(char *str)
{
    int result = 0;
    while (*str != '\0')
        result = (result + *(str++)) % hashsize;
    return result;
}

void check(table *table1, char *name,char testAC) 
{
    int index = hash(name); 
     
    for (int i = 0; i < (int) strlen(name); i++) {
        if(table1[index].str[i] != name[i]) {
            index = (index + 1) % hashsize;
            if (table1[index].str[0] != '\0')
                i = 0;
            else {
                memcpy(table1[index].str, name, strlen(name));
                break;
            }
        }
    }

    if (testAC == 'A' && !table1[index].isAC) { 
        killAC++;
        table1[index].isAC = 1;
        table1[index].firstAC = 1;
    } else if (testAC == 'A' && table1[index].isAC && !table1[index].firstAC) { 
            killAC++;
            nonKillAC--;
            table1[index].firstAC = 1;
    } else if (testAC != 'A' && table1[index].isAC && table1[index].firstAC) {
            killAC--;
            nonKillAC++;
            table1[index].firstAC = 0;
    }
}

int main(int argc, char *argv[])
{
    int n; 
    char buffer[buffer_size], name[buffer_size];
    table table1[hashsize] = {{0}};
    scanf("%d", &n);
     
    for (int i = 0; i < n; i++) {
        scanf("%s", name);
        scanf("%s", buffer);
        check(table1, name, buffer[0]); 
    }
    printf("%d%%\n", (killAC * 100) / (nonKillAC + killAC));
    return 0;
}

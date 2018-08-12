#include <cstdio>
#include <cstdlib>

#define buffer_size 1024
int main(int argc, char *argv[])
{
    int n;
    scanf("%d", &n); 
    getchar(); 
    char buffer[buffer_size];
    int i = 1;
    i = fread(buffer, 1, buffer_size, stdin);
    
    if (i <= 0)
        return 0;

    int j = 0; 
    for (int k = 0; k < n; k++) {
        unsigned long long int o = 0;
        unsigned long long int addW = 0;
        unsigned long long int a = 0;
        unsigned long long int addNew = 0;

        char c;
        while (i > 0 && (c = buffer[j++]) != '\n') {
            if (c == 'O') {
                if (addW) {
                    addNew += addW * o;

                    if (addNew > 1000000007)
                        addNew -= 1000000007;
   
                    addW  = 0;
                }
                a += addNew;
                if (a > 1000000007)
                    a -= 1000000007;
                o++;
            } else if(c == 'w' && o > 0)
                addW++;

            if (j > buffer_size) {
                i = fread(buffer, 1, buffer_size, stdin);
                j = 0;
            }
        }
        printf("%llu\n", a);
    }

    return 0;
}

#include <iostream>

#define SIZE 1500

using namespace std;

unsigned long long computePoly(int poly[7], int x)
{
    unsigned long long aws = 0;
    for (int i = 7 - 1; i > 0; --i, aws *= x) 
        aws += poly[i];
    return aws += poly[0];
}

int main()
{
    int n;
    cin >> n;
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 0, j = 0; i < n; i++) {
        // load all number
        unsigned long long firstLine[SIZE];
        for (int i = 0; i < SIZE; ++i)
            cin >> firstLine[i];

        // get polynomial(1024)
        unsigned long long polyLine = firstLine[1023];
        int poly[7];
        for (int i = 0; i < 7; i++) {
            poly[i] = polyLine & (1024 - 1);
            polyLine = polyLine >> 10;
            // out of range a_i <= 1000
            if (poly[i] > 1000 && poly >= 0)
                goto smart;
        }

        // check all number
        for (int i = 0; i < SIZE; ++i)
            if (firstLine[i] != computePoly(poly, i + 1)) { 
                goto smart;
            }
        
        // dump 
        for (int i = 0; i < 7; ++i)
            cout << poly[i] << (i == 6 ? '\n' : ' ');
        

        continue;
    smart:
        cout << "This is a smart sequence!" << endl;
    }
    cout.flush();
    return 0;
}

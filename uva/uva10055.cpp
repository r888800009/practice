#include <iostream>
#include <cstdlib>

using namespace std;

int main() 
{
    do {
       long long a, b;
       cin >> a >> b;
       if (!cin.eof())
           cout << abs(b - a) << endl;
    } while (!cin.eof());
    return 0;
}


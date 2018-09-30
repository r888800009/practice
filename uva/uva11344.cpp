#include <iostream>

#define NUM_LENGTH 6

using namespace std;

bool divisible(string m, int num)
{
    if (m.length() <= NUM_LENGTH) {
        try {
        int numM = stoi(m);
        if (numM >= num && numM % num == 0) // divisible
            return 1;
        else if (numM == 0)
            return 1;
        else 
            return 0;
        }
        catch (exception &e) {
            cout << " qwe"<<m<<"qweqw"<<endl;
            return 0;
        }
    } else {                         // next
        string next = to_string(stoi(m.substr(0, NUM_LENGTH)) % num);
        next += m.substr(NUM_LENGTH);
        return divisible(next , num);              
    }
}

int main()
{
    int n, n2;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string m;
        cin >> m;
        cout << m;
        cin >> n2;
        int j = 0;
        for (; j < n2; ++j) {
            int num;
            cin >> num;
            if (!divisible(m, num)) {
                cout << " - Simple." << endl;
                goto next;
            }
        }
        cout <<" - Wonderful." << endl;
    next:
        for (++j; j < n2; ++j) {
            int num;
            cin >> num;
        }
    }
    return 0;
}

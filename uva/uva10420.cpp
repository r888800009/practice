#include <iostream>
#include <string>
#include <sstream>
#include <map>

using namespace std;
map<string, int> names;

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; ++i) {
        string getStr;
        stringstream ss; 
        getline(cin, getStr);
        ss << getStr;
        ss >> getStr;
        map<string, int>::iterator it = names.find(getStr);
        if (it == names.end())
            names.insert(pair<string, int>(getStr, 1));
        else 
            it->second++;
    }

    for (map<string, int>::iterator it = names.begin();
         it != names.end(); ++it) 
    {
        cout << it->first << " " << it->second << endl;
    }

    return 0;
}

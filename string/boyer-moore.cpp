#include <fstream>
#include <iostream>

using namespace std;

fstream fs;
string keyword;

int bm() {
    ;
    ;
    return -1;
}

int main(int argc, char *argv[]) {
    if (argc != 3)
        cout << "boyer-moore <file> <keyword>" << endl;
    else {
        fs.open(argv[1], fstream::in);
        keyword = argv[2];
        bm();
        fs.close();
    }

    return 0;
}


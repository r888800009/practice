#include <bitset>
#include <iostream>
#include <string>

using namespace std;

int main() {
  string bin = "1010";

  int int1 = stoi(bin, nullptr, 2);

  cout << int1 << endl;
  cout << bitset<8>(int1) << endl;

  return 0;
}

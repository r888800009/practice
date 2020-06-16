#include <iostream>

using namespace std;
void bar() {
  cout << __FUNCTION__ << endl;
  cout << __LINE__ << endl;
}

void foo() {
  cout << __FUNCTION__ << endl;
  bar();
}

int main() {
  foo();
  cout << __FILE__;
  return 0;
}

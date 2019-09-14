#include <stdio.h>

// enable or disable assert
// #define NDEBUG
#include <assert.h>

int square(int i) {
  return i * i;
  // return i * i + 1;  // assert working
}

int main() {
  int i = square(4);
  assert(i == 16);

  return 0;
}

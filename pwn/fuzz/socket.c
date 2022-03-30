#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
/*
gcc socket.c -o socket -fsanitize=address
afl-clang-fast socket.c -o socket -fsanitize=address
*/

int main(int argc, char *argv[]) {
  // connect to localhost:3456
  // create a socket
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock == -1) {
    perror("socket");
    exit(1);
  }

  // fill in the address of the server
  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(3456);
  addr.sin_addr.s_addr = inet_addr("127.0.0.1");

  // connect!
  if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
    perror("connect");
    exit(1);
  }

  int n = 0, m = 0;
  // read digits from socket
  char buf[0x10];
  while ((n = read(sock, buf, sizeof(buf))) > 0) {
    buf[n] = 0;
    m += atoi(buf);
    printf("%d\n", m);

    // crash if m > 1023
    if (m > 1023) {
      // trigger a segfault
      puts("crashing...");
      char *p = 0;
      *p = 0;
    }
  }

  return 0;
}


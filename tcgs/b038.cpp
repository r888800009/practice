#include <iostream>
#include <vector>

using namespace std;

int N;
int set[8] = {1, 2, 3, 4, 5, 6, 7, 8};
bool select1ed[8] = {0, 0, 0, 0, 0, 0, 0, 0};


int index1;
int select1[10];

void rec(int deep) {
  if (deep <= 0) {
    for (int i = 0; i < index1; i++)
      cout << select1[i];
   
    cout << '\n';
    return;
  }

  for (int i = 0; i < N; i++) {
    if (select1ed[i] == false) {
      select1ed[i] = true;

      select1[index1] = set[i];
      index1++;
      rec(deep - 1);

      index1--;
      select1ed[i] = false;
    }
  }
}

int main() {
  cin >> N;

  index1 = 0;
  rec(N);

  return 0; 
}

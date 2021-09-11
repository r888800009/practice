#include <iostream>
#include <cmath>

using namespace std;

const int EMPTY_GRID = -1;

// index: x
// value: y
int grid[20];

int N;

bool check(int x, int y) {

  // 水平
  if (grid[x] != EMPTY_GRID) {
    //cout << "b";
    return false;
  }
   
  // 垂直
  for (int i = 0; i < N; i++) {
    if (y == grid[i]) {

      //cout << "a";
      return false;
    }
  }

  // 斜線 '\' and 斜線 '/'
  int dx, dy;
  for (int i = 0; i < N; i++) {
    if (grid[i] == EMPTY_GRID)
      continue;

    dx = x - i;
    dy = y - grid[i];
    if (dy == abs(dx)) {
      //cout << "c";
      return false;
    }
  }

  return true;
}

int ans[20];

void rec(int deep) {
  if (deep >= N) {
    for (int x = 0; x < N; x++) {
      cout << ans[x] + 1;
      if (x < N - 1)
        cout << " ";
      else
        cout << "\n";
    }
    
    return;
  }


  for (int x = 0; x < N; x++) {
    // cout << x << " " << deep << '\n';
    if (check(x, deep)) {
      grid[x] = deep;
      ans[deep] = x;
      
      rec(deep + 1);

      grid[x] = EMPTY_GRID;
    }
  }
}

int main() {
  cin >> N;
  
  // init grid
  for (int i = 0; i < N ; i++)
    grid[i] = EMPTY_GRID;
   

  rec(0);

  return 0;
}

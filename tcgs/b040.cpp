#include <iostream>

using namespace std;

int N, max_cost;
int price[30];
int ans[30];
int *stack1 = ans;

bool rec(int cur_cost, int start_index, int deep) {
  if (cur_cost == max_cost) {
    // print
    for (int x = 0; x < deep; x++) {
      cout << ans[x] << ((x < deep - 1)? ' ' : '\n' );
    }

    return true;
  } else if (cur_cost > max_cost ) {
    return false;
  } else if (deep < N) {
    bool solve = false;

    for (int i = start_index; i < N; i++) {
      *stack1 = price[i];
      stack1++;

      if(rec(cur_cost + price[i], i + 1, deep + 1))
        solve = true;

      stack1--;
    }

    return solve;
  } 

  return false;
}

int main() {
  cin >> N >> max_cost;

  for (int i = 0; i < N; i++)
    cin >> price[i];

  if (!rec(0, 0, 0))
    cout << "NO\n";

  return 0;
}

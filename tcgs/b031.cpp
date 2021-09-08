#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int types, capacity;
  cin >> types >> capacity;

  int dp[types][capacity + 1];

  // init 
  for (int i = 0; i < types; i++) {
    for (int j = 0; j <= capacity; j++)
      dp[i][j] = 0;
  }


  for (int i = 0; i < types; i++) {
    int cost, value;
    cin >> cost >> value;
    for (int j = 0; j <= capacity; j++) {
      // 取
      int picked = 0;
      if (j - cost >= 0)
        picked = dp[i][j - cost] + value;

      // 不取
      int not_pick = 0;
      if (i > 0) not_pick = dp[i - 1][j];

      dp[i][j] = max(picked, not_pick);
    }
  }

  cout << dp[types - 1][capacity] << '\n';

  return 0;
}

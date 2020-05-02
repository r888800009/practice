// clang-format off
class Solution {
  vector<int> *coins;
  int notset;
  int *tables;
  int selectLeast(int amount) {
    if (amount < 0)
      return -1;
    if (amount == 0)
      return 0;

    if (tables[amount] != notset)
      return tables[amount];

    int min = -1;

    for (int i = 0; i < coins->size(); i++) {
      int coin = (*coins)[i];
      if (coin == 0)
        continue;

      int subProblem = selectLeast(amount - coin);

      if (amount - coin == 0)
        min = 1;

      if (subProblem != -1 && (min == -1 ||
                               min > 1 + subProblem))
        min = 1 + subProblem;
    }

    return tables[amount] = min;
  }
 
public:
  int coinChange(vector<int>& coins, int amount) {
    this->coins = &coins;
    notset = amount + 1;
    tables = new int[amount + 1];
    for (int i = 0; i < amount + 1; i++)
      tables[i] = notset;

    return selectLeast(amount);
  }
};

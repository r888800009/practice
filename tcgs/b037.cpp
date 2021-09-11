#include <iostream>
#include <vector>

using namespace std;

vector<char> ans;
int range;

void getChar(int deep) {
  if (deep <= 0) {
    for (int i = 0; i < ans.size(); i ++)
      cout << ans[i];

    cout << '\n';
    return;
  }

  for (int i = 0 ; i <= range ; i++) {
    ans.push_back('0'+ i);
    getChar(deep - 1);
    ans.pop_back();
  }
}

int main() {
  int N, M;
  cin >> N >> range ;

  getChar(N);

  return 0;
}

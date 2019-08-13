#include <stack>

class Solution {
  std::stack<int> stack; // store index
public:
  vector<int> dailyTemperatures(vector<int>& T) {
    vector<int> result(T.size());

    for (int i = T.size() - 1; i >= 0; i--) {
      while (stack.size() > 0 && T[stack.top()] <= T[i])
        stack.pop();
      
      if (stack.size() == 0)
        result[i] = 0;
      else 
        result[i] = stack.top() - i;
       
      stack.push(i);
    }

    return result;
  }
};

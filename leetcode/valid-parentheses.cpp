#include<stack>

class Solution {
  std::stack<char> stack;
public:
    bool isValid(string s) {
      for(char& c : s) {
        if (c == '[' || c == '(' || c == '{')
          stack.push(c); 
        else if (c == ']' && stack.size() > 0 && stack.top() == '[')
          stack.pop();
        else if (c == ')' && stack.size() > 0 && stack.top() == '(')
          stack.pop();
        else if (c == '}' && stack.size() > 0 && stack.top() == '{')
          stack.pop();
        else
          return false;
      }
      
      if (stack.size() != 0)
        return false;
      
      return true;
    }
};

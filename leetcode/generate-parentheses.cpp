class Solution {
  vector<string> result;
  
  void gen(string str, int n, int open, int close) {
    if (str.length() == n * 2) {
      result.push_back(str);
      return;
    }
    
    if (open < n)
      gen(str + "(", n, open + 1, close);
    
    if (close < open)
      gen(str + ")", n, open, close + 1);
  }
  
public:
  vector<string> generateParenthesis(int n) {
    gen("", n, 0, 0);
    return result;
  }
};

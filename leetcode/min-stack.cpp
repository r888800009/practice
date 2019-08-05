#include <stack>
class MinStack {
  std::stack<int> min, innerStack;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
      innerStack.push(x);
      if (min.size() == 0)
        min.push(x);
      else 
        min.push(min.top() < x ? min.top() : x);
    }
    
    void pop() {
      if (innerStack.size() > 0) {
        innerStack.pop(); 
        min.pop();
      }
    }
    
    int top() {
      return innerStack.top();
    }
    
    int getMin() {
      return min.top();
    }
};

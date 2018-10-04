#include <iostream>
#include <stack>
#include <map>
using namespace std;

map<char, int> priority;
stack<char> stack1;

int main()
{
    priority.insert(pair<char, int>('*', 5));
    priority.insert(pair<char, int>('/', 5));
    priority.insert(pair<char, int>('+', 10));
    priority.insert(pair<char, int>('-', 10));

    string expr = "a+b*c+(d*e+f+g*h)-i/j+k";
    string result = "";

    cout << expr << endl;
    for (char c : expr) {
        map<char, int>::iterator cIt, topIt;
        if (c == '(') {
            stack1.push(c); 
        } else if (c == ')') {
            while (stack1.top() != '(') 
                result += stack1.top(), stack1.pop();
            
            stack1.pop();
        } else if ((cIt = priority.find(c)) != priority.end()) {
            while (stack1.size() > 0) { 
                topIt = priority.find(stack1.top());
                if (stack1.top() != '(' && cIt->second >= topIt->second) // pop print 
                    result += stack1.top(), stack1.pop();
                else
                    break;
            }
            stack1.push(c);
        } else
            result += c;
    }
    while (stack1.size() > 0)
        result += stack1.top(), stack1.pop();

    cout << result << endl;

    return 0;
}

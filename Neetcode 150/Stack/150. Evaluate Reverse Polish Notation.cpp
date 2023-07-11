#include <iostream>
#include <stack>
#include <string>
#include <vector>
class Solution {
   public:
    int evalRPN(std::vector<std::string>& tokens) {
        std::stack<int> numberStack;
        for (int i = 0; i < tokens.size(); ++i) {
            // if encounter numbers
            if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/") {
                numberStack.push(stoi(tokens[i]));
                continue;
            }
            // if encounter tokens, evaluate the token with the top 2 from the stack
            // and push it back to the top
            int b = numberStack.top();
            numberStack.pop();
            int a = numberStack.top();
            numberStack.pop();
            if (tokens[i] == "+") {
                numberStack.push(a + b);
                continue;
            }
            if (tokens[i] == "-") {
                numberStack.push(a - b);
                continue;
            }
            if (tokens[i] == "*") {
                numberStack.push(a * b);
                continue;
            }
            if (tokens[i] == "/") {
                numberStack.push(a / b);
                continue;
            }
        }
        return numberStack.top();
    }
};
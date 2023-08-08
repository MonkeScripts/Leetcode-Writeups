#include <iostream>
#include <stack>
#include <string>
#include <vector>
class Solution {
   public:
    bool isValid(std::string s) {
        std::vector<char> stack;
        if (s.size() <= 1) return false;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                stack.push_back(s[i]);
                continue;
            }
            if (stack.empty()) return false;
            if ((s[i] == ')' && stack.end()[-1] != '(') || (s[i] == ']' && stack.end()[-1] != '[') || (s[i] == '}' && stack.end()[-1] != '{')) return false;
            stack.pop_back();
        }
        return stack.empty();
    }
};
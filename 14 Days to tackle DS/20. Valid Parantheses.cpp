//Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//Add opening brackets to stack. when encounter closing brackets, check the stack whether the correpsonding opening bracket is present
class Solution {
public:
    bool isValid(string s) {
        vector<char>stack;
        for(int i = 0; i<s.size();++i){
            if(s[i] == '('||s[i] =='{'||s[i] =='[') {
                stack.push_back(s[i]);
                continue;
            }
            if(!stack.empty() && (s[i] ==')' && stack.end()[-1]!='(' || s[i] =='}' && stack.end()[-1]!='{'||s[i] ==']' && stack.end()[-1]!='[')) return false;
            if(stack.empty()) return false;
            stack.pop_back();
        }
        if(!stack.empty()) return false;
        return true;   
    }
};

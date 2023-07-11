#include <iostream>
#include <string>
#include <vector>

class Solution {
   public:
    std::vector<std::string> result;
    // uses backtracking to print out all permutations
    // one main condition we must fulfil would be that the right bracket must never be more than left bracket
    // in our backtracking we therefore need 2 extra parameters for left and right brackets
    // this backtracking method mainly invokes 2 recursive calls:
    // one to add one right bracket and the other to add a left bracket
    // we add extra conditions to implement the constraints above
    void helper(int left, int right, int n, std::string a) {
        if (left > n || right > n || right > left) return;
        if (left == n && right == n) {
            result.push_back(a);
            return;
        }
        helper(left, right + 1, n, a + ')');
        helper(left + 1, right, n, a + '(');
    }
    std::vector<std::string> generateParenthesis(int n) {
        std::string a = "";
        helper(0, 0, n, a);
        return result;
    }
};
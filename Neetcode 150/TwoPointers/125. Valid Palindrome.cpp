#include <iostream>
class Solution {
   public:
    bool isPalindrome(std::string s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            // if the pointes are not alphabet, move the pointer
            if (!isalnum(s[left])) {
                left++;
                continue;
            }
            if (!isalnum(s[right])) {
                right--;
                continue;
            }
            // if the 2 pointers are not equal, return false
            if (tolower(s[left]) != tolower(s[right])) return false;
            left++;
            right--;
        }
        return true;
    }
};
#include <iostream>
class Solution {
   public:
    bool isAnagram(std::string s, std::string t) {
        if (s.size() != t.size()) return false;
        int freq[26] = {0};
        for (int i = 0; i < s.size(); ++i) {
            freq[s[i] - 'a']++;
        }
        for (int i = 0; i < t.size(); ++i) {
            if (freq[t[i] - 'a'] <= 0) return false;
            freq[t[i] - 'a']--;
        }
        return true;
    }
};
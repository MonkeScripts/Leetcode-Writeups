//Given two strings s and t, return true if t is an anagram of s, and false otherwise.
class Solution {
public:
    //hash frequency of letters for both strings, check if they are the same
    bool isAnagram(string s, string t) {
        vector<int>freq(26,0);
        int count = 0;
        for(int i =0; i<s.size();++i){
            freq[s[i]-'a']++;
        }
        for(int i = 0; i<t.size();++i){
            if(freq[t[i]-'a'] < 1) return false;
            freq[t[i]-'a']--;
            count ++;
        }
        if(count< s.size()) return false;
        return true;
    }
};

//Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26,0);
        //hash and check frequency 
        for(int i = 0; i< s.size(); ++i){
            freq[int(s[i])-97] ++;
        }
        for(int i = 0; i< s.size(); ++i){
            //if index alr present, return index
            if(freq[int(s[i])-97] == 1) return i;
        }
        return -1;
    }
};

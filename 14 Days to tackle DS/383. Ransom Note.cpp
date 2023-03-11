//Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> freqmag(26,0);
        //record frequency of letters in magazine
        for(int i = 0; i< magazine.size();++i){
            freqmag[magazine[i]- 'a']++;
        }
        for(int i = 0; i< ransomNote.size();++i){
            //if not in magazinem return false
            if(freqmag[ransomNote[i]-'a'] <1) return false;
            freqmag[ransomNote[i]-'a'] --;
        }
        return true;     
    }
};

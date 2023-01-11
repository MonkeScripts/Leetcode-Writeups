class Solution {
public:
    bool checkfreq(int freq1[],int freq2[]){
          for(int i =0; i< 26;i++){
                if(freq1[i]!=freq2[i]){
                    return false;
                }
            }
            return true;
    }
    bool checkInclusion(string s1, string s2) {
        int length = s1.size();
        if(length> s2.size()) return false;
      // we hash the count of each characters into a list based on alphabetical order
        int freq1[26]={0};
        int freq2[26]={0};
        //we do a for loop to add the frequencies of each char into freq1 and freq2. freq1 does not change as we are finding permutations of freq1 in freq1
        //this for loop runs in freq2 as well so that when we check we only need to care about the addition and subtraction of the last char 
        for(int i = 0; i< length; i++) {
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }
        int index = 0;
        //-1 for the last char in freq2 as would be adding it in the while loop later
        freq2[s2[length-1]-'a'] --;
        while(index + length <= s2.size()){
            //start from index + length as the freq for the first substring is added
            //addition of the last element to window
            freq2[s2[index+length-1]-'a'] ++;
            //check freq
            if(checkfreq(freq1,freq2)) return true;
            //subtraction of first element to window
            freq2[s2[index]-'a']--;
            index ++;
        }
        return false;      
    }
};

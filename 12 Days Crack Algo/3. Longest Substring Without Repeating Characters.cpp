//uses a sliding window technique
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_length = 0;
        int length = 0;
     // we hash the characters in this count array based on their ascii values
        int count[128] ={0};
        int left = 0;
        int right = 0;
        while(right < s.size()){
            //increase the freq of the char in the array
            count[s[right]]++;
          //when freq > 1 means that the same char has been visited before, we therefore have to reset the count array
          //To reset, we use a while loop with the left pointer catching up to the right pointer
            while(count[s[right]] > 1){
                count[s[left]] --;
                left ++;
            }
            right++;
            // find max length based on the difference of left and right pointers
            max_length = max(right - left,max_length);  
        }
        return max_length;      
    }
};

//2 pointer: one at the end and one at the start
//swap the pointers until they reach in the middle
class Solution {
public:
    void reverseString(vector<char>& s) {
       int left = 0;
       int right = s.size() -1;
       while(left <= right){
           char temp = s[left];
           s[left++]= s[right];
           s[right--] = temp;
       }
    }
};

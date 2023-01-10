class Solution {
public:
    string reverseWords(string s) {
        int left = 0;
        int right = 0;
        //iterate through the array
        for(int i =0; i< s.size();i++){
            //if hit space or end of string, we start swapping the indexes using 2 pointer(start and end)
            if(s[i] == ' ' || i == s.size() -1){
                right = i == s.size() -1 ? i : i -1;
                while(left < right){
                    char temp = '/0';
                    temp = s[left];
                    s[left] = s[right];
                    s[right--] = temp;
                    left ++;
                }
              // after the swap, we continue iterating in the array but reset the starting pointer as the i + 1
                left = i+1; 
            }
        }
        return s;   
    }
};

//2 pointer technique
//we are modifying the array in place, we thus have pointer to keep track of which index in array we would be updating
//scan through the array, if number is non zero, update array, the pointer index ++
// in the end, we compare the size of pointer to the original size of array and fill the rest with zeroes
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        int left = 0;
        for(int i =0; i< nums.size();i++){
            if(nums[i] != 0){
                nums[left++] = nums[i];
            }
        }
        while(left<size){
            nums[left++]= 0;
        }
    }
};

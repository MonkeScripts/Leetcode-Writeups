class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        while(left <= right){
            int middle = left + (right-left) /2; //we do this instead of (left + right) because (left + right) could exceed integer values
            if(nums[middle] == target) return middle;
            if(nums[middle] < target) left = middle + 1;
            else right = middle - 1;
        }
        return -1;
    }
};

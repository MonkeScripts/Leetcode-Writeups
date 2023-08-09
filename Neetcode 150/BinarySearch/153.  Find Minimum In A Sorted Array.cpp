#include <iostream>
#include <vector>

class Solution {
   public:
    int _findMin(std::vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int middle = left + (right - left) / 2;
            if (nums[middle] <= nums[right]) {
                right = middle;
            } else {
                left = middle + 1;
            }
        }
        return nums[left];
    }
    int findMin(std::vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int result = 9999;
        while (left <= right) {
            int middle = left + (right - left) / 2;
            // easy way to check if there is any rotation to begin with
            if (nums[middle] > nums[right]) {
                result = std::min(result, nums[right]);
                left = middle + 1;
                continue;
            }
            // we should not not choose min(result,nums[left])
            // possibility of left being higher than middle
            result = std::min(result, nums[middle]);
            right = middle - 1;
        }
        return result;
    }
};
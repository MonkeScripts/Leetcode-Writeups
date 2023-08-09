#include <iostream>
#include <vector>

class Solution {
   public:
    int search(std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int middle = left + (right - left) / 2;
            if (nums[middle] == target) return middle;
            // checks whether the array is rotated from left to middle
            if (nums[middle] >= nums[left]) {  // not rotated
                // if target is within this unrotated range
                if (target >= nums[left] && target <= nums[middle]) {
                    right = middle - 1;
                    continue;
                }
                left = middle + 1;
                continue;
            }
            // right part rotated
            // check right side because right side should be sorted
            // check whether the target falls within the right side range
            if (target > nums[middle] and target <= nums[right]) {
                left = middle + 1;
                continue;
            }
            right = middle - 1;
        }
        return -1;
    }
};
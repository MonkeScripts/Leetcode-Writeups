#include <iostream>
#include <vector>
class Solution {
   public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            // calculate the current sum of the 2 pointers
            int sum = nums[i] + nums[j];
            // if sum = target then return the vector with the result
            if (sum == target) return {i + 1, j + 1};
            // if sum > target
            // We know the array is sorted. We only need to move the right pointer
            // This is because moving the left pointer only increases the current sum
            // Does not make sense to move left and right togther since when we move one pointer we create a new combination
            if (sum > target) j--;
            // if sum < target
            // move right pointer instead. We know that the right pointer already has the largest value
            // Therefore we can only increase the left pointer
            else
                i++;
        }
        return {};  // Target not found
    }
};
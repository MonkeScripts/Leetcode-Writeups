#include <algorithm>
#include <iostream>
#include <vector>
class Solution {
   public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        // sort the array
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> result;
        // test each integer, start with a negative number / zero
        // use 2 pointer technique to search for the remaining 2 integers
        for (int i = 0; i < nums.size(); ++i) {
            // since the numbers are based on the sum and the array is sorted
            // we should break when the are starting a positive number (subsequent additions would not get us 0)
            if (nums[i] > 0) break;
            // remove duplicates, we search for [i-1] because we have incremented i at the start of each loop
            //(check current vs previous)
            if (i != 0 && nums[i] == nums[i - 1]) continue;
            // start our 2 pointer technique with left index being the index after i
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                // if right is negative, means the entire sum is negative, break
                if (nums[right] < 0) break;
                // decrement right pointer
                if (nums[i] + nums[left] + nums[right] > 0) {
                    right--;
                    continue;
                }
                // increment left pointer
                if (nums[i] + nums[left] + nums[right] < 0) {
                    left++;
                    continue;
                }
                // originally added all the vectors to a set which took up a much longer runtime,
                // using pointers to eliminate duplicates is way faster
                //  if equal to zero, add to vector, shift left and right pointers until there are no duplicates
                if (nums[i] + nums[left] + nums[right] == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    // we check with [left + 1] since we increment after
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    left++;
                    right--;
                }
            }
        }
        return result;
    }
};
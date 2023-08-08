#include <iostream>
#include <vector>
class Solution {
   public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        // product of array except self
        // product of anything before the array index and anything after the array index
        std::vector<int> result(nums.size(), 0);
        result[0] = 1;
        // iterate through the left side and tabulate the results
        for (int i = 1; i < nums.size(); ++i) {
            result[i] = nums[i - 1] * result[i - 1];
        }
        // iterate from the back and multiply with the tabulated results
        int prev = 1;
        for (int i = nums.size() - 2; i >= 0; --i) {
            prev *= nums[i + 1];
            result[i] *= prev;
        }
        return result;
    }
};
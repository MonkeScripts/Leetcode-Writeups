#include <iostream>
#include <unordered_map>
#include <vector>
class Solution {
   public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> hash;
        std::vector<int> result;
        for (int i = 0; i < nums.size(); ++i) {
            if (hash.find(target - nums[i]) != hash.end()) {
                result.push_back(i);
                result.push_back(hash[target - nums[i]]);
                return result;
            }
            hash.insert({nums[i], i});
        }
        return result;
    }
};
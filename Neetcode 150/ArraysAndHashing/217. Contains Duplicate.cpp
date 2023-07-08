#include <iostream>
#include <unordered_set>
#include <vector>
class Solution {
   public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::unordered_set<int> hash;
        for (int i = 0; i < nums.size(); ++i) {
            if (hash.find(nums[i]) != hash.end()) return true;
            hash.insert(nums[i]);
        }
        return false;
    }
};
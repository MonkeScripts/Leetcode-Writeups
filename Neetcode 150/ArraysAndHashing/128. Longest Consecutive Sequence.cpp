#include <iostream>
#include <set>
#include <vector>
class Solution {
   public:
    int longestConsecutive(std::vector<int>& nums) {
        if (nums.size() == 0) return 0;
        std::set<int> hash;
        int result = 1;
        int consecutive = 1;
        for (int i = 0; i < nums.size(); ++i) {
            hash.insert(nums[i]);
        }
        std::set<int>::iterator it;
        for (it = ++(hash.begin()); it != hash.end(); ++it) {
            int currNum = *it;
            int prevNum = *prev(it);
            if (currNum == prevNum + 1) {
                consecutive++;
            } else {
                consecutive = 1;
            }
            result = std::max(result, consecutive);
        }
        return result;
    }
};
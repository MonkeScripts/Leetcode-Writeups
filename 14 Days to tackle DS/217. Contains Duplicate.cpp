/** Approach : Using Set **/
// Time Complexity: O(n)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // Create a set...
        unordered_set<int> hash;
        // Traverse all the elements through the loop...
        for(int i = 0; i < nums.size(); ++i) {
            // Searches set. if present, it contains duplicate...
            if(hash.count(nums[i])) return true;
            // insert nums[i] in set...
            hash.insert(nums[i]);
        }
        return false;
    }
};

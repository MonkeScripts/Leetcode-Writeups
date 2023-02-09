class Solution {
public:
    unordered_map<int, int> cache;
    int __rob(vector<int> &nums) {
        return solve(nums.size()-1, nums);
    }
    //memoisation using unordered map
    int solve(int n, vector<int> &nums) {
        if (n == 0)  return nums[0];
        if (n == 1) return max(nums[0], nums[1]);
        if (cache.count(n)) return cache.at(n);
        int res = max(solve(n-1, nums), nums[n] + solve(n-2, nums));
        cache.insert(make_pair(n, res));
        return res;
    }
  //tabulation method
     int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        if(nums.size() == 1) return nums[0];
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        for(int i =2; i< dp.size();++i){
            dp[i] = max(nums[i]+dp[i-2],dp[i-1]);
        }
        return dp.back();
    }
};

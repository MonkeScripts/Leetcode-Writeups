//Find a subarray that gives the maximum total
//We use a dp approach where the state is the max(current index, current index + dp[index-1])
//this way we would know whether its better to extend the subarray or start a new sub array

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> result(nums.size(),0);
        if(result.size() == 1) return nums[0];
        result[0] = nums[0];
        int max_ans = result[0];
        for(int i = 1; i< nums.size();++i){
            result[i] = max(nums[i],nums[i]+result[i-1]);
            max_ans = max(max_ans,result[i]);
        }
        return max_ans;       
    }
};

//Alternative is the kadane's algorithm, which is similar to the current dp approach. Instead of using a vector to tabulate the dp, we just have an extra variable to check whether to extend / start fresh subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        //current max records the current maximum steps before i
        int current_max = -10000;
        int max_ans = -10000000;
        for(int i = 0; i< nums.size();++i){
            current_max = max(nums[i],nums[i]+current_max);
            max_ans = max(max_ans,current_max);
        }
        return max_ans;       
    }
};

class Solution {
public:
    void helper (vector<vector<int>>&result,vector<int>& nums,int leading){
        if(leading >= nums.size()){
            result.push_back(nums);
            return;
        }
        for(int i = leading;i<nums.size();i++){
            swap(nums[i],nums[leading]);
            helper(result,nums,leading+1);
            swap(nums[leading],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>result;
        helper(result,nums,0);
        return result;
        
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> help;
        vector<int> result;
        for(int i = 0; i< nums.size();++i){
            //check for pairs in a hashmap
            if(help.find(target - nums[i])==help.end()){
                help[nums[i]] = i;
            }
            else{
                result.push_back(help[target - nums[i]]);
                result.push_back(i);
                return result;                
            }
        }
        return result;        
    }
};

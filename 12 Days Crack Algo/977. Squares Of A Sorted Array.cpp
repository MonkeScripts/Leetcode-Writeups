class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums){
       vector<int> result(nums.size(),0);
       //2 pointers technique
       // since the array is alr sorted in ascending order,we just need to compare the abs(negative values) against the highest number in the array. We then add the lower number to a new vector
       int left = 0;
       int right = nums.size() -1;
       for(long i = nums.size()-1;i>=0;i--){
           if(abs(nums[left]) > nums[right]){
               result[i] = nums[left] * nums[left];
               left ++;
           }
           else{
               result[i] = nums[right] * nums[right];
               right --;
           }
       }
       return result;
    }
};

//overkill method: using a priority queue

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        priority_queue <int, vector<int>, greater<int>> prio;
        for(int i =0; i < nums.size(); i ++){
            prio.push(nums[i] * nums[i]);
        }
        for(int i =0; i < nums.size(); i ++){
            nums[i] = prio.top();
            prio.pop();
        }
        return nums;        
    }
};

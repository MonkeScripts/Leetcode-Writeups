// Use an unordered map O(1) (lookup time) to store all the inputs in the array
//minus the trget number with the array indexes, look for the subtracted result in the hashmap, if present, return
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        unordered_map<int,int> apple;
        for(int i =0; i< numbers.size();i++){
            apple[numbers[i]] = i;
        }
        for(long i =0; i< numbers.size(); i++){
            if(apple.find(target - numbers[i]) != apple.end()){
                result.push_back(i+1);
                result.push_back(apple[target - numbers[i]]+1);
                return result;
            }
        } 
        return result;       
    }
};

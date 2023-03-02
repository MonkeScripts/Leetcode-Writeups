class Solution {
public:
    bool is_Palindrome(string s, int start,int end){
        while(start<=end){
            if(s[start++] != s[end--]) return false;
        }
        return true;
    }
    void dfs(int index, string s,vector<string> &collection,vector<vector<string>> &result){
        //base case
        if(index== s.size()){
            result.push_back(collection);      
            return;
        }
        //recursive case
        //backtracking approach, iterates throughthe array starting from index
        for(int i = index; i< s.size();++i){
            if(is_Palindrome(s,index,i)){
                //adds palindrome to a vector
                collection.push_back(s.substr(index,i-index+1));
                //calls i+1, checks for the next index
                dfs(i+1,s,collection,result);
                //once recursion ends, vector is addded to result,remove the substr from vector for next iteration 
                collection.pop_back();
            }

        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> collection;
        dfs(0,s,collection,result);      
        return result;  
    }
};

class Solution {
public:
    void generate(int n, int k,vector<int>&grp, vector<vector<int>> &result,int index){
        //base case
        if(grp.size() == k){
            result.push_back(grp);
            return;
        }
        //recursive case
        //choose index
        for(int i = index; i<=n;i++){
            grp.push_back(i);
            generate(n,k,grp,result,i+1);
            grp.pop_back();            
        } 
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int>grp;
        generate(n,k,grp,ans,1);
        return ans;    
    }
};

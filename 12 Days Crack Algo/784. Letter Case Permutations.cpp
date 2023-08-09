class Solution {
public:
    void helper(vector<string>&result,string &current, string&s,int index){
        if(index>= s.size()){
            result.push_back(current);
            return;
        }
        string now = current;
        if(isdigit(s[index])){
            current += s[index];
            helper(result,current,s,index+1);
        }
        else{
            // add small letter
            current += tolower(s[index]);
            helper(result,current,s,index+1);
            // use unchanged string and add cap latter to it
            now += toupper(s[index]);
            helper(result,now,s,index+1);
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string>result;
        string a = "";
        helper(result,a,s,0);
        return result;
        
    }
};

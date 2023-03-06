//create a pascal triangle with a given number of rows

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if(!numRows) return result;
        for(int i = 1; i< numRows+1;++i){
            //start with a vector of size i with value 1 at the start of each row
            vector<int> row(i,1);
            for(int j = 1;j<row.size()-1 && i>2;++j){
                row[j] = result[i-2][j-1] + result[i-2][j];
            }
            result.push_back(row);
        }
        return result;
    }
};

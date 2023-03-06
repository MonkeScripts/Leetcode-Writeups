class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if(mat.size()*mat[0].size() != r*c) return mat;
        int row = 0,col = 0;
        //create the matrix
        vector<vector<int>> result(r,vector<int>(c,0));
        for(int i = 0; i< mat.size();++i){
            for(int j = 0;j<mat[0].size();++j){
                //if col exceeds, we set col = 0 and increase row by 1
                if(col >= c){
                    row ++;
                    col = 0;
                }
                result[row][col]= mat[i][j];
                col++;
            }
        }        
        return result;
    }
};

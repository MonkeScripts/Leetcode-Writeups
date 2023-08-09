//DP approach
//Go down top to bottom to update result vector
//GO back from bottom to top to update vector again
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> result(mat.size(),vector<int>(mat[0].size(),100000));
        for(int i = 0; i< mat.size();i++){
            for(int j = 0; j < mat[0].size();j++){
                if(mat[i][j] == 0) result[i][j] = 0;
                else{
                    if(i>=1) result[i][j] = min(result[i][j],result[i-1][j]+1);
                    if(j>=1) result[i][j] = min(result[i][j],result[i][j-1]+1);

                }
            }
        }
        for(int i = mat.size()-1;i>=0;i--){
            for(int j = mat[0].size() -1; j>=0;j--){
                if(i<mat.size()-1) result[i][j] = min(result[i][j],result[i+1][j]+1);
                if(j<mat[0].size()-1) result[i][j] = min(result[i][j],result[i][j+1]+1);
            }
        }
        return result;        
    }
};

//BFS Approach
class Solution {
public:
    bool check(int row,int col,int rowsize,int colsize){
        if(row<0 || col <0 || row > rowsize -1 || col > colsize -1) return false;
        return true;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>> coordinates;
        vector<vector<int>> result(mat.size(),vector<int>(mat[0].size(),-1));
        for(int i = 0; i< mat.size(); i++){
            for(int j =0; j< mat[0].size(); j++){
                // add all the zero coordinates into a queue
                if(mat[i][j] == 0) result[i][j] = 0,coordinates.push({i,j});
            }
        }
        while(!coordinates.empty()){
            int current_row = coordinates.front().first;
            int current_col = coordinates.front().second;
            coordinates.pop();
            //remove the coordinate from queue, check neighbouring coordinates and add them to the queue
            //-1 means not visited
            //up
            if(check(current_row -1,current_col,mat.size(),mat[0].size()) && result [current_row -1][current_col] == -1){
                result [current_row -1][current_col] = result [current_row][current_col] +1;
                coordinates.push({current_row -1,current_col});
            }
            //down
            if(check( current_row +1,current_col,mat.size(),mat[0].size())   && result [current_row +1][current_col] == -1){
                result [current_row +1][current_col] = result [current_row ][current_col] +1;
                coordinates.push({current_row +1,current_col});
            }
            //left
            if(check( current_row ,current_col-1,mat.size(),mat[0].size())   && result [current_row ][current_col-1] == -1){
                result [current_row ][current_col-1] = result [current_row ][current_col] +1;
                coordinates.push({current_row ,current_col-1});
            }
            //right
            if(check(current_row ,current_col+1,mat.size(),mat[0].size())  && result [current_row ][current_col+1] == -1){
                result [current_row ][current_col+1] = result [current_row ][current_col] +1;
                coordinates.push({current_row ,current_col+1});
            }
        }
        return result;

    }
};

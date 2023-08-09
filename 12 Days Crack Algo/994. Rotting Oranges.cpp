class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        //bfs approach
        // add the rotten  fruits into queue, while poping them, add their neighbouring oranges and increase time counter + 1
        queue<pair<int,int>> rotten;
        int minutes = 0;
        bool orange = false;
        for(int i = 0; i<grid.size();i++){
            for(int j = 0; j< grid[0].size();j++){
                if(grid[i][j] == 1) orange = true;
                if(grid[i][j] == 2) rotten.push({i,j});
            }
        }
        if(rotten.empty()){
            if(orange) return -1;
            return 0;
        }
        while(!rotten.empty()){
            int size = rotten.size();
            for(int i = 0; i< size;i++){
                int row = rotten.front().first;
                int col =  rotten.front().second;
                //add to queue
                if(row >= 1 && grid[row-1][col] == 1) grid[row-1][col] = 2,rotten.push({row-1,col});
                if(row < grid.size() - 1 && grid[row+1][col] == 1) grid[row+1][col] = 2,rotten.push({row+1,col});
                if(col >= 1 && grid[row][col-1] == 1) grid[row][col-1] = 2,rotten.push({row,col-1});
                if(col < grid[0].size()-1 && grid[row][col+1] == 1) grid[row][col+1] = 2,rotten.push({row,col+1});
                //pop
                rotten.pop();
            }
            minutes ++;
        }
        //  check for isolated fresh oranges, if have return -1;
        for(int i = 0; i<grid.size();i++){
            for(int j = 0; j< grid[0].size();j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        return minutes -1;        
    }
};

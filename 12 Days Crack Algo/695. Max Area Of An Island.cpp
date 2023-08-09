class Solution {
public:
    void dfs(vector<vector<int>>& grid,int row, int col,int &area){
        if(grid[row][col] !=1) return;
        // when visited, set grid[row][col] to 2 so as to prevent stack overflow
        grid[row][col] = 2;
        //area is by reference
        area ++;
        if(row >=1) dfs(grid,row-1,col,area);
        if(row < grid.size()-1) dfs(grid,row+1,col,area);
        if(col >= 1)  dfs(grid,row,col-1,area);
        if(col<grid[0].size()-1) dfs(grid,row,col+1,area);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area = 0;
        int max_area = 0;
        for(int i = 0; i< grid.size(); i++){
            for(int j = 0; j< grid[i].size(); j++){
                if(grid[i][j] == 1) 
                {
                    dfs(grid,i,j,area);
                    max_area = max(max_area,area);
                    area = 0;
                }                
            }
        }
        return max_area;    
    }
};

class Solution {
public:
    //adds the path sums to the last row and find its minimum element
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size() == 1) return triangle[0][0];
        for(int i = 1; i<triangle.size();++i){
            for(int j = 0; j<triangle[i].size();++j){
                //index at start of row
                if(j == 0){
                    triangle[i][j]+= triangle[i-1][j];
                    continue;
                }
                //index at end of row
                else if(j == triangle[i].size()-1){
                    triangle[i][j] += triangle[i-1].back();
                    continue;
                }
                triangle[i][j]+= min(triangle[i-1][j-1],triangle[i-1][j]);
            }
        }
        return *min_element(triangle.back().begin(), triangle.back().end());
        
    }
};

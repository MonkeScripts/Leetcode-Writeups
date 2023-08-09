class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0;
        int col = matrix[0].size();
        int low = 0;
        int high = matrix.size()*matrix[0].size() -1;
        //binary search in a box
        while(low<=high){
            int middle = (high + low)/2;
            //achieved via modulus
            if(matrix[middle/col][middle%col] == target) return true;
            if(matrix[middle/col][middle%col]<target) low = middle +1;
            else high = middle -1;
        }
        return false;   
    }
};

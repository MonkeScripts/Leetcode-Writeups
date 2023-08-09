#include <iostream>
#include <vector>

class Solution {
   public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        int left = 0;
        int right = matrix.size() * matrix[0].size() - 1;
        int col = matrix[0].size();
        // searching in a box
        while (left <= right) {
            int middle = (left + right) / 2;
            // determine which row and col they middle belongs to
            if (matrix[middle / col][middle % col] == target) return true;
            if (matrix[middle / col][middle % col] > target)
                right = middle - 1;
            else
                left = middle + 1;
        }
        return false;
    }
};
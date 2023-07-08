#include <iostream>
#include <set>
#include <vector>

class Solution {
   public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        std::set<int> row_hash;
        std::set<int> col_hash;
        std::set<int> box_hash;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] != '.') {
                    if (row_hash.find(board[i][j]) != row_hash.end()) return false;
                    row_hash.insert(board[i][j]);
                }
                if (board[j][i] != '.') {
                    if (col_hash.find(board[j][i]) != col_hash.end()) return false;
                    col_hash.insert(board[j][i]);
                }
                if (board[3 * (i / 3) + j / 3][3 * (i % 3) + j % 3] != '.') {
                    if (box_hash.find(board[3 * (i / 3) + j / 3][3 * (i % 3) + j % 3]) != box_hash.end()) return false;
                    box_hash.insert(board[3 * (i / 3) + j / 3][3 * (i % 3) + j % 3]);
                }
            }
            row_hash.clear();
            col_hash.clear();
            box_hash.clear();
        }
        return true;
    }
};
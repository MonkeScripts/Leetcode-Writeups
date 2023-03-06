//Given a sudoku puzzle, check whether the box is a valid sudoku
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> row_set;
        unordered_set<char> col_set;
        unordered_set<char> box_set;
        for(int i = 0; i< board.size();++i){
            for(int j = 0; j< board[0].size();++j){
                //row
                if(board[i][j] != '.'){
                    if(row_set.find(board[i][j])!= row_set.end()) return false;
                    row_set.insert(board[i][j]);
                }
                //column
                if(board[j][i] != '.'){
                    if(col_set.find(board[j][i])!= col_set.end()) return false;
                    col_set.insert(board[j][i]);
                }
                //box
                if(board[3*(i/3)+j/3][3*(i%3)+j%3] !='.'){
                    if(box_set.find(board[3*(i/3)+j/3][3*(i%3)+j%3]) != box_set.end()) return false;
                    box_set.insert(board[3*(i/3)+j/3][3*(i%3)+j%3]);
                }
            }
            row_set.clear();
            col_set.clear();
            box_set.clear();
        }
        return true;
        
    }
};

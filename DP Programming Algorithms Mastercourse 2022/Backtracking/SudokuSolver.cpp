#include <iostream>
#include <vector>

bool valid(int board[][9],int row,int col,int target){
    //check col and row
    for(int i =0;i<9;i++){
        if(board[row][i] == target || board[i][col] == target ) return false;
    }
    //check box
    //find starting indexes
    int x = (row/3)*3;
    int y = (col/3)*3;
    for(int i = x; i< x+3;i++){
        for(int j = y; j < y+3; j++){
            if(board[i][j] == target) return false;
        }
    }
    return true;
}
bool sudokusolver(int board[][9],int row,int col){
    if(row > 8){
        for(int i =0; i< 9;i++){
            for(int j =0; j<9;j++){
                std::cout<<" "<<board[i][j];
            }
            std::cout<<std::endl;
        }
        return true;
    } 
    //end of a row
    if(col>8) return sudokusolver(board,row+1,0);
    if(board[row][col] !=0) return sudokusolver(board,row,col+1);
    for(int i = 1; i<10;i++){
        if(valid(board,row,col,i)){
            board[row][col] = i;
            if(sudokusolver(board,row,col+1)) return true;  
        } 
    }
    board[row][col] = 0;
    return false;    
}

int main(){

    int sudokuboard[9][9] =
    {
    {3,5,7,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,9,0},
    };
    if(!sudokusolver(sudokuboard,0,0)) std::cout<<"no solutions"<<std::endl;
}

#include<iostream>

void print(int input, int board[][20]){
    for(int i = 0; i< input; i++){
        for(int j = 0; j< input; j++){
            std::cout<<board[i][j];
        }
        std::cout<<""<<std::endl;
    }
}
bool safe(int input, int board[][20],int row, int col){
    //check col
    for(int i = 0; i< row;i++){
            if(board[i][col] == 1) return false;
        }
    //left diagonal
    int x = row;
    int y = col;
    while(x>=0 && y>=0){
        if(board[x][y] == 1) return false;
        x --;
        y --;
    }
    //right diagonal
    x = row;
    y = col;
    while(x>=0 && y>=input){
        if(board[x][y] == 1) return false;
        x --;
        y ++;
    }
    return true;
}
int nqueens(int board[][20],int input,int row){
    //base case
    //reach row == input, return true
    if(row >= input){
        print(input,board);
        //return true;
        return 1;
    }
    //recursive case: try to add a queen on every row, if not possible, return false
    int ways = 0;
    for(int j =0; j< input; j++){ //checks through every col
        if(safe(input,board,row,j)){
            board[row][j] = 1;
            //check for next row
            //bool success = nqueens(board,input,row+1);
            //if(success) return true; 
            ways += nqueens(board,input,row+1);
            // if no success -> backtrack
            board[row][j] = 0; //reset
        }
    }
    //if none in the row can fulfil nqueens
    return ways;
}

int main(){
    int board[20][20]= {0};
    int input = 4;
    int ans = nqueens(board,4,0);
    std::cout<<ans;

 }

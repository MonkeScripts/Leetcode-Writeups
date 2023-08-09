#include<iostream>
#include<vector>
using namespace std;
int main(){
    int target = 12;
    int numbers[] = {2,7,4,5,19};
    int size = sizeof(numbers)/sizeof(numbers[0]);
    vector<vector<int>>table(size+1,vector<int>(target+1,0));
    //create a table that lists out all the possibilities (columns: 0 to target , rows: 0 to size)
    table[0][0] = 1; //obv possible to create 0 from 0 in column and 0 in row 
    //first row rest are all 0s, not possible to form any other non 0 values in column by '0' from row
    for(int i = 1; i<= size; ++i){
        //row by row tabulation 
        for(int j = 0; j<=target;++j){
            //exclusion:if previous index is possible to form the target,since the target does not change, it is still possible for the next index
            table[i][j] = table[i-1][j];
            //inclusion
            if(j-numbers[i] >=0){
                //check whether the subtracted number can be formed by checking the previous row 
                table[i][j] |= table[i-1][j-numbers[i]];
            }              
        }
    }
    cout<<table[size][target]<<endl;
}


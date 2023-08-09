#include<iostream>
#include<vector>
using namespace std;

int main(){
    int target = 12;
    int numbers[] = {2,7,4,5,19};
    int size = sizeof(numbers)/sizeof(numbers[0]);
    //we can improve the space complexity of the tabulation method by only keeping 1 row at a time. whatever values we have on the current row can be overwritten to form the new row
    //in this case, since the row only needs to be overwritten, dp[x][y] |= dp[x][y-j-numbers[i]]  (old data from previous row (x-1) |= dp[y-j-numbers[i]])
    vector<int>table(target+1,0);
    table[0] = 1;
    //time o(n*sum) 
    for(int i = 1; i<= size; ++i){
        //we start from the back so that whatever value we change wont affect future calculations in the same row
        for(int j = target; j>=0;--j){
            if(j - numbers[i] >=0){
                table[j] |= table[j - numbers[i]];
            } 
        }
    }
    cout<<table[target]<<endl;

}

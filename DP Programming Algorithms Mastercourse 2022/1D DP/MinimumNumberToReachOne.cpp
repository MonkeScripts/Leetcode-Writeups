#include <iostream>
#include <vector>
using namespace std;
//find the minimum number of steps for a number to reach one 
//there's only 3 ways: -1,/2,/3
int ways(int nums,vector<int>&memo){
    if(nums <= 1) return 0;
    //link the ans' mem address to the memo[nums] address
    int &ans = memo[nums];
    if(memo[nums] != -1) return ans;
    ans = 1000000000;
    //we try all the possible ways and get the combination of operators to get the minimum number of steps
    if(nums %2 ==0){
        ans = min(ans, ways(nums/2,memo));
    }
    if(nums %3 ==0){
        ans = min(ans, ways(nums/3,memo));
    }
    ans = min(ans, ways(nums-1,memo));
    ans ++;
    return ans;
}

int main(){
    int num = 10;
    vector<int> memo(1000000,-1);
    cout<<ways(num,memo)<<endl;
}

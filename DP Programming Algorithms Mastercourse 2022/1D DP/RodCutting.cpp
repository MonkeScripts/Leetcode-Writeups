#include <iostream>
#include <vector>
using namespace std;
//Given a rod of length n  and array prices of length n denoting the cost of pieces of the rod of length 1 to n, 
//find the maximum amount that can be made if the rod is cut up optimally.
//arr [1,2,3,4,6,7] length 1 price 1. Length 2 price 2....length 5 price 6 etc.
//Alternative 
vector<int>memo(10000,-1);
int rodCutting(int n, int prices[]){
    //base case
    if(n == 0) return 0;
    if(memo[n] != -1) return memo[n];
    //recursive case
    int ans = 0;
    //starting from firstindex
    for(int i =1;i<=n;++i){
        ans = max(ans,prices[i]+rodCutting(n-i,prices));
    }
    return memo[n] = ans;

}

int main(){
    int n = 8;
    int prices[] = {1,3,4,5,7,9,10,11};
    vector<int>dp(n,0);
    //state is the maximum amount that can be made on that cut
    dp[0] =prices[0];
    dp[1] = max(prices[0],prices[1]);
    for(int i =2; i< n;++i){
        cout<<i;
        //when cut is larger than half of the rod, we can find a complement for the cut => prices[i](current cut) + dp[n-i-2](max price of the complement)
        if(i>n/2 && i<n-1){
            //compare current cut + complement vs cutting the previous index
            dp[i] = max(prices[i]+dp[n-i-2],dp[i-1]);
            cout<<" "<<dp[i]<<endl;
            continue;
        }
        //if the cut is smaller than half, we choose whether to cut the current / previous
        dp[i] = max(prices[i],dp[i-1]);
        cout<<" "<<dp[i]<<endl;
    }
    cout<< dp.end()[-1]<<endl;
}

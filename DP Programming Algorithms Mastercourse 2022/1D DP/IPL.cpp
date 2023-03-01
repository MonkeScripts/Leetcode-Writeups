#include <vector>
using namespace std;
//given array, find maximum value provided one cannot choose 3 consecutive days
int main(){
    vector<int> earnings = {3,2,1,1,2,3,1,3,2,1};
    vector<int> dp(earnings.size(),0);
    //our state is the maximum one could earn on that day (he can choose not to earn on ith day itself)
    //first 3 days
    dp[0] = earnings[0];
    dp[1] = earnings[0]+earnings[1];
    dp[2] = max(earnings[2]+dp[0],dp[1]);
    for(int i = 3; i< earnings.size();++i){
        //our state is broken down into whether he chooses ith day or not
        //if yes -> consider the configurations 
        //either he chooses dp[i-3] + a[i-1] + a[i]  || [dp[i-3]] [] [a[i-1]] [a[i]] ||
        //or he chooses dp[i-2] + a[i] || [dp[i-3]] [dp[i-2]] [] [a[i]]  dp[i-2] gives the max value so we do not need dp[i-3] here
        dp[i] = max(max(earnings[i]+earnings[i-1]+dp[i-3],earnings[i]+dp[i-2]),dp[i-1]);
    }
    cout<<dp.end()[-1]<<endl;    
}

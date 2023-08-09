#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<pair<int,int>> market = {{1,8},{2,4},{3,0},{2,5},{2,3}};
    int sackSize = 4;
    vector<int> dp(sackSize+1,0);
    //checks each item in the market
    for(int i = 0; i< market.size();++i){
        //tabulate the maximum value given size j of the backpack
        //starts from the back of the row 
        //start from the back to reduce the number of checks since at later dps the backpack fills faster
        for(int j = sackSize;j>=0;j--){
            //max of either including or not including
            //include: dp[j-market[i].first]+market[i].second) current value of item + maximum value of the remaining space in the backpack
            if(j-market[i].first>=0)dp[j]=  max(dp[j],dp[j-market[i].first]+market[i].second);
        }
    }
    cout<<dp.end()[-1]<<endl;

}

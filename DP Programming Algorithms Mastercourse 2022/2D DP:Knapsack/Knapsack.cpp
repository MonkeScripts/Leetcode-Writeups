#include<iostream>
#include<vector>
using namespace std;
//given a market with the weight and value of an item as well as a knapsack with a fixed size, find the most value I can get from filling the sack
vector<pair<int,int>> market;
vector<vector<int>> memo(1000,vector<int>(1000,-1));

int maxSack(int numItems,int size){
    //base cases
    //ans shld not be a global since it would affect max()
    if(size < 0) return 0;
    if(numItems < 0) return 0;
    int &ans = memo[numItems][size];
    if(ans!=-1)return ans;
    ans = 0;
    //add to sack
    if(size>=market[numItems].first){
        //o(n) knapsack: able to add the same item multiple times
        // main difference is we add another comparison  numItems -1(move to next item) vs numItems(stay at the same item)
     ans = max(market[numItems].second + maxSack(numItems-1,size - market[numItems].first),market[numItems].second + maxSack(numItems,size - market[numItems].first));
        //normal knapsack
     ans = market[numItems].second + maxSack(numItems-1,size - market[numItems].first);
    }
    //dont add, get max of (adding the item , not adding the item)
    return ans = max(ans,maxSack(numItems-1,size));

}


int main(){
    market = {{1,8},{2,4},{3,0},{2,5},{2,3}};
    int size = 4;
    int numberOfItems = 5;
    int ans = maxSack(numberOfItems-1,size);
    cout<<ans<<endl;
}

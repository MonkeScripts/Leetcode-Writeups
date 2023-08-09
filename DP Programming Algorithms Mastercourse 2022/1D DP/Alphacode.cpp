#include<iostream>
#include<vector>
using namespace std;
//Given a string of numbers, suppose '1' is 'a','2' is 'b' ....'26' is z
//find the maximum number of letters/words that can be formed 
vector<int> memo;
int dp(int index,string sequence){
    //we choose index by index
    //if index reaches the end, we return 1 (new way found!)
    if(index >= sequence.size()) return 1;
    if(memo[index] != -1) return memo[index];
    int ways = 0;
    //single characters
    if(sequence[index] >= '1' && sequence[index]<='9') {
        ways += dp(index+1,sequence);
    }
    //double characters e.g. '26'
    if(index +1<sequence.size() && sequence[index] == '1'){
        ways += dp(index+2,sequence);
    }
    if(index +1<sequence.size() && sequence[index] == '2'&&sequence[index+1]<='6'){
        ways += dp(index+2,sequence);
    }
    return memo[index] = ways;
}
int main(){
    string sequence = "251144";
    memo.resize(sequence.size()+1,-1);
    cout<<dp(0,sequence)<<endl;
}

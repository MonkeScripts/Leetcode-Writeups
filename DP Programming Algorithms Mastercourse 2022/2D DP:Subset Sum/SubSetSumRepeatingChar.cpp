#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> memo(5,vector<int>(20,-1));
bool repeatingchar(int numbers[],int index,int target){
    if(index == -1) return (target == 0);
    if(memo[index][target] != -1) return memo[index][target];
    bool ans = false;
    //we can keep subtracting and check
    if(target >= numbers[index]){
        ans |= repeatingchar(numbers,index,target - numbers[index]);
    }
    ans |= repeatingchar(numbers,index-1,target);
    return memo[index][target] = ans;
}
int main(){
    int numbers[] = {2,7,4,5,19};
    int target = 20;
    int size = 5;
    cout<<repeatingchar(numbers,size-1,target)<<endl;
}

#include <iostream>
//given a target number and an array of integers,determine if subset of an array exists that equal to this target number
using namespace std;
//main idea is to choose either to subtract or not subtract the array values from the target number, eventually if the target number is 0 then it exists 

//this check is not tested
bool check(int numbers[],int size, int index, int target){
    //base case
    if(index>= size) return false;
    if(target == numbers[index]) return true;
    if(size <= 0) return false;        
    return check(numbers,size,index+1,target) || check(numbers,size,index+1,target-numbers[index]);
}

//alternative solution: subtracts all the way, return true if reaches 0, false if not 
bool alternative(int numbers[],int index, int sum){
    //base case
    if(index < 0) return (sum == 0);
    bool ans = false;
    //choice to include
    if(sum>=numbers[index]){
        ans |= alternative(numbers,index-1,sum-numbers[index]);
    }
    //choice to exclude,if one of them is fulfilled , return true
    ans |= alternative(numbers,index-1,sum);
    return ans;

}
//prints the values 
void printSubsetSum(int numbers[],int index, int target){
    if(index == -1) return;
    if(alternative(numbers,index-1,target -numbers[index])){
        cout<<numbers[index]<<" ";
        printSubsetSum(numbers,index-1,target - numbers[index]);
    }
    else if(alternative(numbers,index-1,target)){
        printSubsetSum(numbers,index-1,target);
    }
    return;
}
int main(){
    int numbers[] = {2,7,4,5,19};
    int size = 5;
    printSubsetSum(numbers,size-1,28);
    cout<<check(numbers,5,0,15)<<endl;
    cout<<alternative(numbers,size-1,12)<<endl;
}

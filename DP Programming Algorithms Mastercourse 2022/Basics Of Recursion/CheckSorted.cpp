#include<iostream>
#include<vector>
//checks whether an array is sorted
bool check(int index,std::vector<int> a){
  //base case
   if(index == a.size()-1){
    return true;
   }
  //check current index and index+1 and calls recursion for the next index
   if(a[index]<a[index+1] && check(index+1,a)){
    return true;
   }
   return false;
}
int main(){
    std::vector<int> array = {1,2,3,4};
    std::cout<<check(0,array)<<std::endl;
}

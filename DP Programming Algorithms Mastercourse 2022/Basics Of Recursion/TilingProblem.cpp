#include<iostream>
int tiling_ways(int n){
    if(n<0)return 0;
    //once ir cannot fit length, return 1
    if(n <= 3) return 1;
    //recursive call to check max number
    return tiling_ways(n-4) + tiling_ways(n-1);
}
int main(){
    int n = 4;
    std::cout<<tiling_ways(n)<<std::endl;
}

#include <iostream>
//find number of ways to pair friends up. Friends can either be alone/paired
int pairing(int n){
    if(n == 0) return 1;
    if(n == 1) return 1;
    if(n == 2) return 2;
    if(n == 3) return 4;
    //we look at smaller cases 
    //we think about what if a person is alone ->return pairing(n-1)
    //what if a person pairs up with another -> n-1 pairs possible,therefore (n-1)*pairing(n-1)
    //add both cases
    return pairing(n-1) + (n-1)*pairing(n-2);
}
int main(){
    std::cout<<pairing(5);
}

#include <iostream>
//bit wise method to check for even
//num&1 == 1-> odd (bitwise and) 
int fastpower(int num, int pow){
    if(pow == 0) return 1;
    //even
    if(!(pow & 1)) return fastpower(num*num,pow/2);
    //odd
    return num * fastpower(num,pow-1);
}
int alternative(int num,int pow){
    if(pow == 0) return 1;
     //odd
    if(pow & 1) return num * alternative(num,pow/2) * alternative(num,pow/2);
    //even
    return alternative(num,pow/2) * alternative(num,pow/2);
}
int main(){
    int num = 2;
    int pow = 10;
    std::cout<<fastpower(num,pow)<<std::endl;
    std::cout<<alternative(num,pow)<<std::endl;
}

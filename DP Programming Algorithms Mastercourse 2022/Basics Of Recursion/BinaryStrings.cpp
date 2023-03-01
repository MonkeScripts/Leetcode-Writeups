#include <iostream>
//count number of ways to form a binary string with length n where there cannot be consecutive '1's 
int binary_strings(int n){
    if(n == 0)return 1;
    if(n == 1)return 2;
    if(n== 2) return 3;
    // we add the number of ways if 
    //1.add 0 at the start or 2. add 1 at the start(must follow up with a 0)
    return binary_strings(n-1)+binary_strings(n-2);
}
int main(){
    std::cout<<binary_strings(4)<<std::endl;
}

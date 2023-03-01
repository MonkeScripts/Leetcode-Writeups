#include <iostream>

int power(int num, int pow){
    //base case
    if(pow == 0) return 1;
    //recursive case
    return num * power(num,pow -1);
}
int main(){
    int num = 3;
    int pow = 3;
    std::cout<<power(num,pow)<<std::endl;
}

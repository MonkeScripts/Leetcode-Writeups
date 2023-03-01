#include <iostream>
//top down
void printIncreasing(int num){
    if(num == 0)return;
    printIncreasing(num-1);
    std::cout<< num <<std::endl;//action after recursion -> completes the stack before execution

}
//bottom up 
void printDecreasing(int index){
    if(index == 0){
        return;
    }
    std::cout<< index <<std::endl;
    return printDecreasing(index - 1);//executes while making the stack
}

int main(){
    int num = 5;
    //printDecreasing(5);
    printIncreasing(5);
}

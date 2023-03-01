#include <iostream>
//counter for open and close
void generate_brackets(int input, int index,std::string output,int open,int close){
    //base case
    if(index >= input*2){
        std::cout<<output<<std::endl;
        return;
    }
    //recursive case
    // have to put open when open smaller than half of the string 
    if(open< input){
        //output += '('; //cannot do this as once the recursion ends..
        generate_brackets(input,index+1,output+'(',open+1,close);
    }
    // it runs this if statement, output has changed and therefore would not get the right result
    if(close<open){
        //output += ')';
        generate_brackets(input,index+1,output+')',open,close+1);
    }
}
int main(){
    int input =5;
    std::string answer;
    generate_brackets(input,0,answer,0,0);
}

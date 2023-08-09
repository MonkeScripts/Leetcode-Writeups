#include <iostream>
/*
                a
               /  \
              ab
            /   \ 
          abc    a /0 return
        /    \
       abc/0  ab/0 return
    (return)    

*/
void alternative(std::string input,int index, int other_index,std::string output){
    if(input[index] == '\0'){
        output[other_index] = '\0';// closes the string
        std::cout<<output<<std::endl;
        return;
    }
    output[other_index] = input[index];
    alternative(input,index+1,other_index+1,output);
    //overwrite the output index, other_index does not change
    alternative(input,index+1,other_index,output);
}
int main(){
    std::cout<<"here"<<std::endl;
    std::string input = "abc";
    std::string output = "   ";
    alternative(input,0,0,output);
}

#include <iostream>
#include <vector>
//Given an array of duty hours, find the best way to skive. Special rule: No Person can go 3 days in a row without duty
int main(){
    std::vector<int> result(10,0);
    int dutylist[10]= {3,2,1,1,2,3,1,3,2,1};
    //add the first 3 days in
    result[0] = dutylist[0];
    result[1] = dutylist[1];
    result[2] = dutylist[2];
    for(int i = 3; i< 10;++i){
        //state person choosing the last day of duty + min days(dp) before reaching the last day
        result[i] = std::min(std::min(result[i-1],result[i-2]),result[i-3]) + dutylist[i];
    }
    //checks last 3 values of dp array to get the lowest duty hours
    std::cout<<std::min(std::min(result.end()[-1],result.end()[-2]),result.end()[-3])<<std::endl;
}

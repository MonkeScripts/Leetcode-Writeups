class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t result = n;
        int count = 0;
        for(int i = 0; i<32;i++){
            //query 1 bits with a for loop
            result = result&(1<<i);
            if(result >= 1) count++;
            result = n;            
        }
        return count;
    }
};

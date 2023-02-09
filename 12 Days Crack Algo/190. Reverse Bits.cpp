class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for(int i  =0; i< 32;++i){
            //mod 2 would get the value of last bit on the right
            result += (n%2) << (31-i);
            n >>=1;
        }
        return result;
        
    }
    //Alternative
    uint32_t _reverseBits(uint32_t n) {
        uint32_t result = 0;
        for(int i  =0; i< 32;++i){
            //query then set
            if(n & (1<<i)){
                result |= (1<<31-i);
            }
        }
        return result;
    }      
};

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 0 || n<=-2147483648) return false;
        //query n-1 bits, if it is a power of 2, it shld be in a 1000... format. Bitwise and with 0111.... will give 0, returning true
        return !(n & (n-1));
    }
};

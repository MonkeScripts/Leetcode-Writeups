class Solution {
public:
    int memostairs(int n,vector<long>&stairstab){
        //memoisation
        if(n <=0) return 0;
        if(n == 1) return 1;
        if(n==2) return 2;
        if(stairstab[n] != 0) return stairstab[n];
        return stairstab[n] = memostairs(n-1,stairstab) + memostairs(n-2,stairstab);
    }
    int climbStairs(int n) {
        vector<long> stairstab(n+1,0);
        return memostairs(n,stairstab);
        //tabulation
        // stairstab[0] = 1;
        // stairstab[1] = 2;
        // for(int i = 2; i<=n; i++){
        //     stairstab[i] = stairstab[i-1] + stairstab[i-2];
        // }
        // return stairstab[n-1];        
    }
};

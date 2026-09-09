class Solution {
public:
    long long countCommas(long long n) {
        long long res = 0  ;
        if(n<1e3) return 0 ;
        res+= 0 ; 
        if(n<1e6) return res+n-1e3+1 ;
        res+=n-1e3+1 ;
        if(n<1e9) return res+n-1e6+1 ;
        res+=n-1e6+1 ;
        if(n<1e12) return res + n-1e9+1 ;
        res+=n-1e9+1 ;
        if(n<1e15) return res + n-1e12+1 ;
        res+=n-1e12+1;
        return res+ n-1e15+1 ;
    }
};
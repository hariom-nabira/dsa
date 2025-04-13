class Solution {
public:
    static const int M = 1e9+7;
    int countGoodNumbers(long long n) {
        int ans = (myPow(5,n/2)*myPow(4,n/2))%M;
        return (n&1)? (1LL*ans*5)%M:ans;
    }
    long long myPow(int x,long long n){
        long long ans=1;
        while(n!=0){
            if(n&1)
                ans = (ans*x)%M;
            x = (1LL*x*x)%M;
            n>>=1;
        }
        return ans;
    }
};
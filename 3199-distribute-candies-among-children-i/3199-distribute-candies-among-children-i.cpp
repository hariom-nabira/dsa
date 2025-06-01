class Solution {
private:
    long long nC2(int n){
        if(n<=0) return 0;
        return (1LL*n*(n-1))/2;
    }
public:
    int distributeCandies(int n, int limit) {
        return nC2(n +2) - 3* nC2(n-(limit+1) +2) + 3* nC2(n-2*(limit+1) +2) - nC2(n - 3*(limit+1) +2);
    }
};
class Solution {
private:
    int MOD = 1e9+7;
public:
    int numTilings(int n) {
        if(n<=1) return 1;
        else if(n==2) return 2;
        else if(n==3) return 5;
        vector<int> dp(n+1, -1);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;
        for(int i=4; i<=n; i++){
            dp[i] = (dp[i-1]*2LL + dp[i-3]) % MOD;
        }
        return dp[n];
    }
};
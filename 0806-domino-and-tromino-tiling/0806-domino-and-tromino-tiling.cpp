class Solution {
private:
    int MOD = 1e9+7;
public:
    int numTilings(int n) {
        vector<int> dp(n+1, -1);
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2; i<=n; i++){
            dp[i] = (dp[i-1] + dp[i-2]) % MOD;
            for(int j=i-3; j>=0; j--){
                dp[i] = (dp[i] + (2*dp[j])%MOD ) %MOD;
            }
        }
        return dp[n];
    }
};
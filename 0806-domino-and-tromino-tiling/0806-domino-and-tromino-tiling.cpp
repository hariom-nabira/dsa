class Solution {
private:
    int MOD = 1e9+7;
    int helper(int n, vector<int> &dp){
        if(dp[n]!=-1){
            return dp[n];
        }
        if(n<=1) return 1;
        int ans = ( helper(n-1, dp) + helper(n-2, dp) )%MOD;
        for(int i=3; i<=n ;i++){
            ans = ( ans + (2 * helper(n-i, dp))%MOD ) %MOD;
        }
        return dp[n] = ans;
    }
public:
    int numTilings(int n) {
        vector<int> dp(n+1, -1);
        return helper(n, dp);
    }
};
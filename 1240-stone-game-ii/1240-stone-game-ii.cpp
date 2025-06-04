class Solution {
private:
    int helper(int isAliceTurn, int ind, int m, vector<vector<vector<int>>> &dp, vector<int> &piles, vector<int> &suff){
        int n=piles.size();
        if(ind>=n) return 0;
        if(dp[isAliceTurn][ind][m] != -1) return dp[isAliceTurn][ind][m];
        if(ind + 2*m >= n) return dp[isAliceTurn][ind][m] = suff[ind];
        int ans = 0;
        for(int x=1; x<=2*m; x++){
            ans = max(ans, suff[ind]-helper(1-isAliceTurn,ind+x,max(x,m),dp,piles,suff));
        }
        return dp[isAliceTurn][ind][m] = ans;
    }
public:
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        vector dp(2, vector(n, vector<int> (2*n + 1,-1)));
        // dp[isAlice'sTurn][index][m] is the max number of stones Alice can get starting from 'index' and 'm' and considering whose turn it is
        vector<int> suff(n);
        suff[n-1] = piles[n-1];
        for(int i=n-2; i>=0 ; i--){
            suff[i] = piles[i]+suff[i+1];
        }
        return helper(1,0,1,dp,piles,suff);
    }
};
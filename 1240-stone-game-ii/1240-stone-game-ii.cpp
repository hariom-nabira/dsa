class Solution {
private:
    int helper(int ind, int m, vector<vector<int>> &dp, vector<int> &suff){
        int n=suff.size();
        // checking this first allows dp[][]'s second dimention to be allocated 'n'. If you check later then you will have to give '2*n'
        if(ind + 2*m >= n) return suff[ind];
        // if(ind>=n) return 0; we never call with ind>=n so not needed
        if(dp[ind][m] != -1) return dp[ind][m];
        int ans = 0;
        for(int x=1; x<=2*m; x++){
            ans = max(ans, suff[ind]-helper(ind+x,max(x,m),dp,suff));
            // suff[ind]-helper(ind+x,max(x,m),dp,suff) is basically all that available - what the max other player could take
        }
        return dp[ind][m] = ans;
    }
public:
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        vector dp(vector(n, vector<int> (n,-1)));
        // dp[index][m] is the max number of stones the current player can get starting from 'index' and 'm'
        vector<int> suff(n);
        suff[n-1] = piles[n-1];
        for(int i=n-2; i>=0 ; i--){
            suff[i] = piles[i]+suff[i+1];
        }
        return helper(0,1,dp,suff);
    }
};
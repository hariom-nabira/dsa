class Solution {
private:
    int lcs(string s, string rev){
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(s[i-1]==rev[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][n];
    }
public:
    int longestPalindromeSubseq(string s) {
        string rev(s.rbegin(), s.rend());
        return lcs(s,rev);
    }
};
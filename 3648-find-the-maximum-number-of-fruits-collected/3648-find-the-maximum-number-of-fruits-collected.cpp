class Solution {
private:
    int helper1(vector<vector<int>> &dp, vector<vector<int>>& fruits, int i, int j){
        int n=fruits.size();
        if(i>=n) return INT_MIN;
        if(j==0){
            return (i==n-1) ? fruits[i][j] : INT_MIN;
        }
        if(dp[i][j] != -1) return dp[i][j];
        int top = helper1(dp, fruits, i-1, j-1);
        int left = helper1(dp, fruits, i, j-1);
        int bottom = helper1(dp, fruits, i+1, j-1);

        int mx = max({top, left, bottom});
        return dp[i][j] = (mx==INT_MIN) ? mx : mx+fruits[i][j];
    }
    int helper2(vector<vector<int>> &dp, vector<vector<int>>& fruits, int i, int j){
        int n=fruits.size();
        if(j>=n) return INT_MIN;
        if(i==0){
            return (j==n-1) ? fruits[i][j] : INT_MIN;
        }
        if(dp[i][j] != -1) return dp[i][j];
        int left = helper2(dp, fruits, i-1, j-1);
        int top = helper2(dp, fruits, i-1, j);
        int right = helper2(dp, fruits, i-1, j+1);

        int mx = max({top, left, right});
        return dp[i][j] = (mx==INT_MIN) ? mx : mx+fruits[i][j];
    }
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int ans=0, n=fruits.size();
        for(int i=0; i<n; i++){
            ans += fruits[i][i];
        }
        vector<vector<int>> dp(n, vector<int>(n, -1));
        ans += helper1(dp, fruits, n-1, n-2);
        ans += helper2(dp, fruits, n-2, n-1);
        return ans;
    }
};
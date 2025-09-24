class Solution {
private:
    int helper(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dp){
        int n = grid.size(), m = grid[0].size();
        if(i>=n || j>=m) return 1e9;
        if(dp[i][j] != -1) return dp[i][j];
        if(i==n-1 && j==m-1) return grid[i][j];
        return dp[i][j] = grid[i][j] + min(helper(grid, i+1, j, dp), helper(grid, i, j+1, dp));
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return helper(grid, 0, 0, dp);
    }
};
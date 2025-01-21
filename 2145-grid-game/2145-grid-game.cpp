class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n=grid[0].size();
        long long ans = LLONG_MAX, topSum = 0, bottomSum = 0;
        for(int i=0; i<n; i++){
            topSum += grid[0][i];
        }
        for(int i=0; i<n; i++){
            topSum -= grid[0][i];
            ans = min(ans, max(bottomSum, topSum));
            bottomSum += grid[1][i];
        }
        return ans;
    }
};
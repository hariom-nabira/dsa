class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n=grid[0].size();
        vector<long long> preSumDown(n+1), postSumUp(n+1);
        for(int i=0; i<n; i++){
            preSumDown[i+1] = preSumDown[i] + grid[1][i];
            postSumUp[n-i-1] = postSumUp[n-i] + grid[0][n-i-1];
        }
        long long ans = LLONG_MAX;
        for(int i=0; i<n; i++){
            ans = min(ans, max(preSumDown[i],postSumUp[i+1]));
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> dx = {1,-1,0,0};
    vector<int> dy = {0,0,1,-1};
    int dfs(int i, int j, vector<vector<int>> &grid){
        if(grid[i][j]<=0) return 0;
        int ans = grid[i][j], n = grid.size(), m=grid[0].size();
        grid[i][j] = -1;
        for(int k=0; k<4; k++){
            int x = i+dx[k], y = j+dy[k];
            if(x<0 || x==n || y<0 || y==m) continue;
            ans += dfs(x,y,grid);
        }
        return ans;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int ans = 0, n = grid.size(), m = grid[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                ans = max(ans, dfs(i,j,grid));
            }
        }
        return ans;
    }
};
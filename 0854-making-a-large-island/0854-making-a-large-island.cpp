class Solution {
public:
    vector<int> dx = {1,-1,0,0};
    vector<int> dy = {0,0,1,-1};

    int dfs(int r, int c, vector<vector<int>>& grid, int marker){
        grid[r][c] = marker;
        int ans = 1, n=grid.size();
        for(int d=0; d<4; d++){
            int X = r+dx[d], Y = c+dy[d];
            if(X>=0 && X<n && Y>=0 && Y<n && grid[X][Y]==1){
                ans += dfs(X,Y,grid,marker);
            }
        }
        return ans;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size(), comp = 2;
        map<int, int> compToCount;
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    compToCount[comp] = dfs(i,j,grid,comp);
                    ans = max(ans, compToCount[comp]);
                    comp++;
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==0){
                    int temp = 1;
                    set<int> st;
                    for(int d=0; d<4; d++){
                        int X = i+dx[d], Y = j+dy[d];
                        if(X>=0 && X<n && Y>=0 && Y<n){
                            st.insert(grid[X][Y]);
                        }
                    }
                    for(auto &e: st) temp += compToCount[e];
                    ans = max(ans, temp);
                }
            }
        }
        return ans;
    }
};
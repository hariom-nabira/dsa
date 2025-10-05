// DFS from oceans
class Solution {
private:
    vector<vector<int>> dir = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    void dfs(int i, int j, vector<vector<int>> &heights, vector<vector<bool>> &vis, int prev){
        int n=heights.size(), m=heights[0].size();
        if(i<0 || i>=n || j<0 || j>=m || vis[i][j] || heights[i][j]<prev) return;
        vis[i][j] = true;
        for(auto &d: dir){
            dfs(i+d[0], j+d[1], heights, vis, heights[i][j]);
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size(), m=heights[0].size();
        vector<vector<bool>> pacific(n, vector<bool>(m));
        vector<vector<bool>> atlantic(n, vector<bool>(m));
        for(int i=0; i<n; i++){
            dfs(i,0,heights,pacific,-1);
            dfs(i,m-1,heights,atlantic,-1);
        }
        for(int j=0; j<m; j++){
            dfs(0,j,heights,pacific,INT_MIN);
            dfs(n-1,j,heights,atlantic,INT_MIN);
        }
        vector<vector<int>> ans;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(pacific[i][j] && atlantic[i][j]) ans.push_back({i,j});
            }
        }
        return ans;
    }
};
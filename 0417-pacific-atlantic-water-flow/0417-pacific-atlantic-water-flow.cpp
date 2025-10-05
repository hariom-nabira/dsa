// BFS from oceans
class Solution {
private:
    vector<vector<int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    
    void bfs(queue<vector<int>> &q, vector<vector<int>> &heights, vector<vector<bool>> &vis){
        int n=heights.size(), m=heights[0].size();
        while(!q.empty()){
            int i = q.front()[0], j = q.front()[1];
            q.pop();
            for(auto &d: dir){
                int x = i+d[0], y = j+d[1];
                if(x<0 || x>=n || y<0 || y>=m || vis[x][y] || heights[x][y] < heights[i][j]) continue;
                vis[x][y] = true;
                q.push({x,y});
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size(), m=heights[0].size();
        vector<vector<bool>> pacific(n, vector<bool>(m));
        vector<vector<bool>> atlantic(n, vector<bool>(m));
        queue<vector<int>> qP, qA;
        for(int i=0; i<n; i++){
            qP.push({i,0});
            pacific[i][0] = true;
            qA.push({i,m-1});
            atlantic[i][m-1] = true;
        }
        for(int j=0; j<m; j++){
            qP.push({0,j});
            pacific[0][j] = true;
            qA.push({n-1,j});
            atlantic[n-1][j] = true;
        }
        bfs(qP,heights,pacific);
        bfs(qA,heights,atlantic);
        vector<vector<int>> ans;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(pacific[i][j] && atlantic[i][j]) ans.push_back({i,j});
            }
        }
        return ans;
    }
};
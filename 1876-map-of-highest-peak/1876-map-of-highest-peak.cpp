class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        //multi-source bfs
        int n = isWater.size(), m = isWater[0].size();
        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};
        vector<vector<int>> ans(n, vector<int>(m,-1));
        queue<pair<int,int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(isWater[i][j]){
                    ans[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        int len=1;
        while(!q.empty()){
            int sz = q.size();
            for(int k=0; k<sz; k++){
                auto &[i,j] = q.front();
                for(int d=0; d<4; d++){
                    int x = i+dx[d], y = j+dy[d];
                    if(x>=0 && x<n && y>=0 && y<m && ans[x][y]==-1){
                        ans[x][y] = len;
                        q.push({x,y});
                    }
                }
                q.pop();
            }
            len++;
        }
        return ans;
    }
};
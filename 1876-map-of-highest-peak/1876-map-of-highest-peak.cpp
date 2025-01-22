class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        //multi-source bfs
        int n = isWater.size(), m = isWater[0].size();
        vector<vector<int>> ans(n, vector<int>(m));
        queue<pair<int,int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(isWater[i][j]) q.push({i,j});
            }
        }
        int len=1;
        while(!q.empty()){
            int sz = q.size();
            for(int k=0; k<sz; k++){
                auto [i,j] = q.front();
                q.pop();
                checkAndSet(i+1, j, n, m, len, isWater, ans, q);
                checkAndSet(i-1, j, n, m, len, isWater, ans, q);
                checkAndSet(i, j+1, n, m, len, isWater, ans, q);
                checkAndSet(i, j-1, n, m, len, isWater, ans, q);
            }
            len++;
        }
        return ans;
    }
    void checkAndSet(int i, int j, int n, int m, int len, vector<vector<int>> &isWater, vector<vector<int>> &ans, queue<pair<int,int>> & q){
        if(i<0 || i==n || j<0 || j==m || isWater[i][j]) return;
        isWater[i][j] = 1;
        ans[i][j] = len;
        q.push({i,j});
    }
};
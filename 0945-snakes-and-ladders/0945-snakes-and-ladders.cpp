class Solution {
private:
    int n;
    pair<int,int> helper(int val){
        int r=(val-1)/n, c=(val-1)%n;
        if(r&1) c = n-1-c;
        r = n-1-r;
        return {r,c};
    }
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        n = board.size();
        queue<int> q;
        vector<bool> visited(n*n +1, false);
        q.push(1);
        visited[1] = true;
        int ans=0;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0; i<sz; i++){
                int curr=q.front(); q.pop();
                for(int dice=1; dice<=6 && curr+dice <= n*n; dice++){
                    int next = curr+dice;
                    auto [r,c] = helper(next);
                    if(board[r][c] != -1){
                        next = board[r][c];
                    }
                    if(next==n*n) return ans+1;
                    if(!visited[next]){
                        visited[next] = true;
                        q.push(next);
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};
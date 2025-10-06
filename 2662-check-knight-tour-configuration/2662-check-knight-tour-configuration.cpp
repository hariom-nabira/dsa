class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        if(grid[0][0]) return false;
        int n=grid.size();
        vector<vector<int>> moves(n*n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                moves[grid[i][j]] = {i,j};
            }
        }
        for(int i=1; i<n*n; i++){
            if(abs((moves[i][0] - moves[i-1][0]) * (moves[i][1] - moves[i-1][1])) != 2) return false;
        }
        return true;
    }
};
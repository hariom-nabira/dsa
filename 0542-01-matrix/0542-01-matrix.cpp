class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size(), m=mat[0].size();
        int inf = n+m;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]==0) continue;
                int left = inf, top = inf;
                if(i>0) top = mat[i-1][j];
                if(j>0) left = mat[i][j-1];
                mat[i][j] = min(left,top)+1;
            }
        }
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                if(mat[i][j]==0) continue;
                int right = inf, bottom = inf;
                if(i<n-1) bottom = mat[i+1][j];
                if(j<m-1) right = mat[i][j+1];
                mat[i][j] = min(mat[i][j], min(bottom, right)+1);
            }
        }
        return mat;
    }
};
class NumMatrix {
private:
    vector<vector<int>> psum;
public:
    NumMatrix(vector<vector<int>>& matrix){
        int n=matrix.size(), m=matrix[0].size();
        psum = vector(n+1, vector<int>(m+1));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                psum[i][j] = psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1] + matrix[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        // we get coordinates 0-indexed, we convert to 1-based
        row1++, col1++, row2++, col2++;
        return psum[row2][col2] - psum[row1-1][col2] - psum[row2][col1-1] + psum[row1-1][col1-1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
class Solution {
private:
    bool canPlace(int r, int c, vector<int> &rowToCol){
        for(int i=0; i<r; i++){
            if(rowToCol[i] == c) return false;
            if(abs(r-i) == abs(rowToCol[i]-c)) return false;
        }
        return true;
    }
    void helper(int r, vector<int> &rowToCol, vector<string> &curr, vector<vector<string>> &ans){
        int n = rowToCol.size();
        if(r==n){
            ans.push_back(curr);
            return;
        }
        for(int c=0; c<n; c++){
            if(canPlace(r,c,rowToCol)){
                curr[r][c] = 'Q';
                rowToCol[r] = c;
                helper(r+1, rowToCol, curr, ans);
                rowToCol[r] = 0;
                curr[r][c] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> curr(n, string(n,'.'));
        vector<int> rowToCol(n, -1);
        helper(0,rowToCol,curr,ans);
        return ans;
    }
};
class Solution {
public:
    void helper(int r, vector<int> &placed, vector<string> &curr, vector<vector<string>> &ans){
        int n=curr.size();
        if(r==n){
            ans.push_back(curr);
            return;
        }
        for(int j=0; j<n; j++){
            bool canPlace = true;
            for(int i=0; i<r; i++){
                if(placed[i]==j || abs(placed[i]-j) == (r-i)){
                    canPlace=false;
                    break;
                }
            }
            if(canPlace){
                curr[r][j] = 'Q';
                placed[r] = j;
                helper(r+1, placed, curr, ans);
                placed[r] = -1;
                curr[r][j] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> curr(n, string(n, '.'));
        vector<int> placed(n, -1);
        helper(0,placed,curr,ans);
        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> row = vector<vector<int>>(9, vector<int> (9, 0));
    vector<vector<int>> col = vector<vector<int>>(9, vector<int> (9, 0));
    vector<vector<int>> grid = vector<vector<int>>(9, vector<int> (9, 0));
    
    bool helper(int r, int c, vector<vector<char>> &board){
        if(r==9) return true;
        if(c==9) return helper(r+1, 0, board);
        if(board[r][c]!='.') return helper(r, c+1, board);
        for(int k=0; k<9; k++){
            if(!row[r][k] && !col[c][k] && !grid[(r/3)*3 + c/3][k]){
                board[r][c] = '1'+k;
                row[r][k] = col[c][k] = grid[(r/3)*3 + c/3][k] = 1;
                if(helper(r, c+1, board)) return true;
                row[r][k] = col[c][k] = grid[(r/3)*3 + c/3][k] = 0;
                board[r][c] = '.';
            }
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j]=='.') continue;
                row[i][board[i][j]-'1'] = 1;
                col[j][board[i][j]-'1'] = 1;
                grid[(i/3)*3 + j/3][board[i][j]-'1'] = 1;
            }
        }
        helper(0,0,board);
    }
};
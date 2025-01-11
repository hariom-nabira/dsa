class Solution {
public:
    bool helper(int i, int j, vector<vector<char>> &board, string &word, int ind){
        if(ind==word.size()) return true;
        int n=board.size(), m=board[0].size();
        if(i<0 || i>=n || j<0 || j>=m || board[i][j]!=word[ind]) return false;
        char og=word[ind];
        board[i][j] = '#';
        if( helper(i-1, j, board, word, ind+1) || 
            helper(i+1, j, board, word, ind+1) || 
            helper(i, j-1, board, word, ind+1) || 
            helper(i, j+1, board, word, ind+1) ){
            return true;
        }
        board[i][j] = og;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size(), m=board[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(helper(i,j,board,word,0)) return true;
            }
        }
        return false;
    }
};
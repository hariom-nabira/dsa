class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;
        int i=1, MOD=1e9+7;
        while(n>0){
            if(n&1) powers.push_back(i);
            i<<=1; n>>=1;
        }
        int p=powers.size();
        vector<vector<int>> ans(p, vector<int>(p));
        for(int i=0; i<p; i++){
            int curr=1;
            for(int j=i; j<p; j++){
                curr = (1LL*powers[j]*curr)%MOD;
                ans[i][j] = curr;
            }
        }
        vector<int> res;
        for(auto &q: queries){
            res.push_back(ans[q[0]][q[1]]);
        }
        return res;
    }
};
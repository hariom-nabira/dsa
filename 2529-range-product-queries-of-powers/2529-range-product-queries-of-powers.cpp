class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;
        int i=1, MOD=1e9+7;
        while(n>0){
            if(n&1) powers.push_back(i);
            i<<=1;
            n>>=1;
        }
        vector<int> res;
        for(auto &q: queries){
            int ans = 1;
            for(int i=q[0]; i<=q[1]; i++){
                ans = (1LL*ans*powers[i])%MOD;
            }
            res.push_back(ans);
        }
        return res;
    }
};
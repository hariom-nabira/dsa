class Solution {
private:
    string ring, key;
    vector<vector<int>> dp, occ;
    int rsz,ksz;
    int helper(int ri, int ki){
        if(ki == ksz) return 0;
        if(dp[ri][ki] != -1) return dp[ri][ki];
        vector<int> &v = occ[key[ki]-'a'];
        int m = v.size();
        int clc = (lower_bound(v.begin(), v.end(), ri) - v.begin()) % m;
        int aclc = (clc-1+m) % m;
        clc = v[clc];
        aclc = v[aclc];
        int ans = min(1 + min(abs(clc-ri), rsz-abs(clc-ri)) + helper(clc, ki+1),
                      1 + min(abs(aclc-ri), rsz-abs(aclc-ri)) + helper(aclc, ki+1));
        return dp[ri][ki] = ans;
    }
public:
    int findRotateSteps(string ring, string key) {
        vector<vector<int>> occ(26, vector<int>());
        rsz=ring.size();
        ksz=key.size();
        for(int i=0; i<rsz; i++){
            occ[ring[i]-'a'].push_back(i);
        }
        this->occ = occ;
        this->ring = ring;
        this->key = key;
        this->dp = vector<vector<int>> (rsz, vector<int>(ksz, -1));
        return helper(0,0);
    }
};
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        vector<int> mp(100);
        for(auto &v: dominoes){
            int num = max(v[0],v[1])*10 + min(v[0],v[1]);
            mp[num]++;
        }
        int ans=0;
        for(auto &e:mp) ans += (e*(e-1))/2;
        return ans;
    }
};
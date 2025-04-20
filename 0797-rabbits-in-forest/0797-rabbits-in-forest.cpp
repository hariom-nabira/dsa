class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int,int> mp;
        for(auto &e: answers) mp[e+1]++;
        int ans=0;
        for(auto &[f,s]: mp){
            ans += (s/f + (s%f != 0)) * f;
        }
        return ans;
    }
};
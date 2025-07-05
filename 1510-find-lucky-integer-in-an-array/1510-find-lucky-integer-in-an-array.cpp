class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> mp;
        for(auto &e: arr) mp[e]++;
        int ans=-1;
        for(auto &[f,s]:mp){
            if(f==s) ans=max(ans, f);
        }
        return ans;
    }
};
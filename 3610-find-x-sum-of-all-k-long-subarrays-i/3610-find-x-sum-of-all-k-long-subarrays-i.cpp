class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int l=0, n=nums.size();
        unordered_map<int,int> mp;
        vector<int> ans;
        for(int r=0; r<n; r++){
            // expand window
            mp[nums[r]]++;
            // shrink window
            if(r-l+1 > k){
                mp[nums[l++]]--;
            }
            // calc ans for valid windows
            if(r-l+1 == k){
                vector<pair<int, int>> v;
                for(auto &p: mp){
                    v.push_back({p.second, p.first});
                }
                sort(v.rbegin(), v.rend());
                int res=0, sz = v.size();
                for(int i=0; i<sz && i<x; i++){
                    res += v[i].first * v[i].second;
                }
                ans.push_back(res);
            }
        }
        return ans;
    }
};
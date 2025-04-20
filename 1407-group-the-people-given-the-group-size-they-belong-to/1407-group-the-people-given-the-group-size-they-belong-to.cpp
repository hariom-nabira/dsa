class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& a) {
        vector<vector<int>> ans;
        int n = a.size();
        vector<vector<int>> mp(n+1);
        for(int i=0; i<n; i++){
            mp[a[i]].push_back(i);
            if(mp[a[i]].size()==a[i]){
                ans.push_back(mp[a[i]]);
                mp[a[i]].clear();
            }
        }
        return ans;
    }
};
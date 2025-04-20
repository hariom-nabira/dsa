class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& a) {
        vector<vector<int>> ans;
        map<int,vector<int>> mp;
        int n = a.size();
        for(int i=0; i<n; i++){
            mp[a[i]].push_back(i);
            if(mp[a[i]].size()==a[i]){
                ans.push_back(mp[a[i]]);
                mp[a[i]] = vector<int>();
            }
        }
        return ans;
    }
};
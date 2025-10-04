class Solution {
  public:
    vector<vector<int>> permuteUnique(vector<int>& arr) {
        vector<vector<int>> ans;
        set<vector<int>> s;
        sort(arr.begin(), arr.end());
        do{
            if(s.count(arr)) continue;
            ans.push_back(arr);
            s.insert(arr);
        }while(next_permutation(arr.begin(), arr.end()));
        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows==1) return {{1}};
        vector<vector<int>> ans = {{1}, {1,1}};
        for(int i=3; i<=numRows; i++){
            vector<int> curr(i,1);
            for(int j=1; j<i-1; j++){
                curr[j] = ans.back()[j-1]+ans.back()[j];
            }
            ans.push_back(curr);
        }
        return ans;
    }
};
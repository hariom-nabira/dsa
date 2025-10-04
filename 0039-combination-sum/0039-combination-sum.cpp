class Solution {
private:
    void helper(vector<vector<int>> &ans, vector<int> &curr, vector<int>& candidates, int start, int targetLeft){
        if(!targetLeft) ans.push_back(curr);
        if(targetLeft < 0) return;
        for(int i=start; i<candidates.size(); i++){
            curr.push_back(candidates[i]);
            helper(ans, curr, candidates, i, targetLeft-candidates[i]);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        helper(ans, curr, candidates, 0, target);
        return ans;
    }
};
class Solution {
public:
    void helper(vector<int> &nums, int i,  vector<int> &curr, int target, vector<vector<int>> &ans){
        if(target<=0){
            if(target==0) ans.push_back(curr);
            return;
        }
        for(int j=i; j<nums.size(); j++){
            curr.push_back(nums[j]);
            helper(nums, j, curr, target-nums[j], ans);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        helper(candidates, 0, curr, target, ans);
        return ans;
    }
};
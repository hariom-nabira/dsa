class Solution {
public:
    void helper(vector<int> &nums, int i, int currSum, vector<int> &curr, int target, vector<vector<int>> &ans){
        if(currSum>target) return;
        if(i==nums.size()){
            if(currSum==target) ans.push_back(curr);
            return;
        }
        helper(nums, i+1, currSum, curr, target, ans);
        curr.push_back(nums[i]);
        currSum += nums[i];
        helper(nums, i, currSum, curr, target, ans);
        curr.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        helper(candidates, 0, 0, curr, target, ans);
        return ans;
    }
};
class Solution {
public:
    void helper(vector<int> &nums, vector<int> &curr, vector<vector<int>> &ans, int i){
        if(i==nums.size()){
            ans.push_back(curr);
            return;
        }
        helper(nums, curr, ans, i+1);
        curr.push_back(nums[i]);
        helper(nums, curr, ans, i+1);
        curr.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        helper(nums, curr, ans, 0);
        return ans;
    }
};
class Solution {
private:
    void helper(vector<vector<int>> &ans, vector<int> &curr, vector<int> &nums, int start){
        ans.push_back(curr);
        for(int i=start; i<nums.size(); i++){
            if(i>start && nums[i]==nums[i-1]) continue;
            curr.push_back(nums[i]);
            helper(ans, curr, nums, i+1);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(nums.begin(), nums.end());
        helper(ans, curr, nums, 0);
        return ans;
    }
};
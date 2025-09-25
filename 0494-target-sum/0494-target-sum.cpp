// memoizing the subset generation
// O(2^n) --> O(n * totalSum)

class Solution {
private:
    int totalSum;
    int helper(vector<int> &nums, int i, int curr, int target, vector<vector<int>> &dp){
        if(i==nums.size()) return curr==target;
        if(dp[i][curr + totalSum] != -1) return dp[i][curr + totalSum];
        return dp[i][curr + totalSum] = helper(nums, i+1, curr+nums[i], target, dp) + helper(nums, i+1, curr-nums[i], target, dp);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        totalSum = accumulate(nums.begin(), nums.end(), 0);
        int n=nums.size();
        vector<vector<int>> dp(n, vector<int> (2*totalSum + 1, -1));
        return helper(nums, 0, 0, target, dp);
    }
};
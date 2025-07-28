class Solution {
private:
    int helper(vector<int> &nums, int i, int curr, int &maxOr){
        int n=nums.size();
        if(i==n) return curr==maxOr;
        return helper(nums, i+1, curr|nums[i], maxOr) + helper(nums, i+1, curr, maxOr);
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;
        for(auto &e: nums) maxOr |= e;
        return helper(nums, 0, 0, maxOr);
    }
};
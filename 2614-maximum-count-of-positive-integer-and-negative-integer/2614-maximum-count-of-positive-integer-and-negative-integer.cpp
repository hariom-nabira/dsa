class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n=nums.size();
        int low = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        int high = upper_bound(nums.begin(), nums.end(), 0) - nums.begin();
        return max(low, n-high);
    }
};
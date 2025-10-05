class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int ans=0;
        for(int i=0; i<nums.size(); i++){
            if(i&1) ans -= nums[i];
            else ans += nums[i];
        }
        return ans;
    }
};
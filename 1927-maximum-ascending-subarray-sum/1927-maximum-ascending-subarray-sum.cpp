class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n=nums.size(), curr = nums[0], ans=0;
        for(int i=1; i<n; i++){
            if(nums[i]>nums[i-1]){
                curr += nums[i];
            }else{
                ans = max(ans, curr);
                curr = nums[i];
            }
        }
        ans = max(ans, curr);
        return ans;
    }
};
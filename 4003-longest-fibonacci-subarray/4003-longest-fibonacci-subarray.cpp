class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size(), ans=2, curr=2;
        for(int i=2; i<n; i++){
            if(nums[i] == nums[i-1]+nums[i-2]){
                curr++;
            }else{
                ans = max(ans, curr);
                curr = 2;
            }
        }
        ans = max(ans, curr);
        return ans;
    }
};
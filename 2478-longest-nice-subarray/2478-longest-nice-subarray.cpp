class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int l=0, n=nums.size(), ans=1;
        int mask=0;
        for(int r=0; r<n; r++){
            //shrinking the window by removing nums[l] from curr
            while(mask & nums[r]){
                mask ^= nums[l++];
            }
            //adding nums[r] to curr
            mask |= nums[r];
            //updating ans
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};
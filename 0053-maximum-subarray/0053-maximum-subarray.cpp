class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=INT_MIN, curr=0, n=nums.size();
        for(int i=0; i<n; i++){
            curr += nums[i];
            ans = max(curr, ans);
            if(curr<0) curr=0;
        }
        return ans;
    }
};
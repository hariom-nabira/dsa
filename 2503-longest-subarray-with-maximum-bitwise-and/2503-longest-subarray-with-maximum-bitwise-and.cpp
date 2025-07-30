class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        int curr=0, n=nums.size(), ans=0;
        for(int i=0; i<n; i++){
            if(nums[i]==mx){
                curr++;
            }else{
                ans = max(ans,curr);
                curr=0;
            }
        }
        ans = max(ans,curr);
        return ans;
    }
};
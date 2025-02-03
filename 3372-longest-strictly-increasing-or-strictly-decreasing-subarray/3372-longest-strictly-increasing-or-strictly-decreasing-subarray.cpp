class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size(), incLength=1, decLength=1, ans=1;
        for(int i=1; i<n; i++){
            if(nums[i]>nums[i-1]){
                decLength=1;
                incLength++;
                ans = max(ans, incLength);
            }else if(nums[i]<nums[i-1]){
                incLength=1;
                decLength++;
                ans = max(ans, decLength);
            }else{
                incLength=1;
                decLength=1;
            }
        }
        return ans;
    }
};
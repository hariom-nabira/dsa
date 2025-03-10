class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size(), l=0;
        long long ans=0, currSum=0;
        unordered_map<int,int> freq;
        for(int r=0; r<n; r++){
            freq[nums[r]]++;
            currSum += nums[r];
            while(r-l+1>k || freq[nums[r]]>1){
                currSum -= nums[l];
                freq[nums[l++]]--;
            }
            if(r-l+1 == k){
                ans = max(ans, currSum);
            }
        }
        return ans;
    }
};
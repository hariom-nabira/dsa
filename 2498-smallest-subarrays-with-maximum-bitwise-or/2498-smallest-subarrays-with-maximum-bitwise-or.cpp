class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n), lastIndexWithBit(32, -1);
        for(int i=n-1; i>=0; i--){
            int mx=i;
            for(int bit=0; bit<32; bit++){
                if(nums[i] & (1<<bit)){
                    lastIndexWithBit[bit] = i;
                }else{
                    mx = max(mx, lastIndexWithBit[bit]);
                }
            }
            ans[i] = mx-i+1;
        }
        return ans;
    }
};
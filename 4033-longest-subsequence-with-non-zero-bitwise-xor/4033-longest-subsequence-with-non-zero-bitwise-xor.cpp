class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xr = 0, n = nums.size(), cnt=0;
        for(auto &e: nums){
            xr ^= e;
            cnt += (e!=0);
        }
        if(!cnt) return 0;
        return (xr)? n: n-1;
    }
};
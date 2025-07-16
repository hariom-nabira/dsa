class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n=nums.size(), odd=0, even=0, alternate=1;
        for(int i=0; i<n; i++){
            if(nums[i]&1) odd++;
            else even++;
            
            if(i>0 && nums[i]%2 != nums[i-1]%2){
                alternate++;
            }
        }
        return max({odd, even, alternate});
    }
};
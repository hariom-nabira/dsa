class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        int i=0, j=nums.size()-1;
        long long ans=0;
        while(i<j){
            if ((0LL+nums[i]+nums[j]) <= upper){
                ans+=j-i;
                i++;
            }else{
                j--;
            }
        }
        i=0, j=nums.size()-1;
        while(i<j){
            if ((0LL+nums[i]+nums[j]) < lower){
                ans-=j-i;
                i++;
            }else{
                j--;
            }
        }
        return ans;
    }
};
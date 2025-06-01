// for numbers bigger than long long __int128

typedef __int128 biggie;

class Solution {
private:
    bool helper(vector<int> &nums, int i, long long curr, long long target){
        if(curr>target) return false;
        int n=nums.size();
        if(i==n){
            return curr==target;
        }
        return helper(nums, i+1, curr*nums[i], target) || helper(nums, i+1, curr, target);
    }
public:
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        biggie prod = 1;
        int n=nums.size();
        for(int i=0; i<n; i++){
            prod *= nums[i];
            if(prod > (biggie)target * target) return false;
        }
        if(prod != (biggie)target*target) return false;
        return helper(nums,0,1,target);
    }
};
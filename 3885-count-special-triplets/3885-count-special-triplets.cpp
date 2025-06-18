class Solution {
private:
    const int MOD = 1e9 +7;
public:
    int specialTriplets(vector<int>& nums) {
        unordered_map<int,int> pre,suff;
        int n=nums.size(), ans=0;
        for(int i=0; i<n-2; i++){
            pre[nums[i]]++;
        }
        suff[nums[n-1]]++;
        for(int i=n-2; i>0; i--){
            int twice = 2*nums[i];
            ans = (ans + (1LL * pre[twice]*suff[twice])%MOD) % MOD;
            suff[nums[i]]++;
            pre[nums[i-1]]--;
        }
        return ans;
    }
};
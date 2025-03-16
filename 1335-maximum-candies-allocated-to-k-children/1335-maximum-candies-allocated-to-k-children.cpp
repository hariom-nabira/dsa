class Solution {
public:
    int maximumCandies(vector<int>& nums, long long k) {
        int mx = *max_element(nums.begin(), nums.end());
        int l=0, r=mx;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(helper(nums,mid,k)){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return l-1;
    }
    bool helper(vector<int> &nums, int mid, long long k){
        if(mid==0) return true;
        long long currFreq=0;
        for(auto &e:nums){
            currFreq += e/mid;
        }
        return currFreq>=k;
    }
};
class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int l=0, r=queries.size(), ans = -1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(helper(nums,queries,mid)){
                ans = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return ans;
    }
    bool helper(vector<int> &nums, vector<vector<int>> &queries, int k){
        int n=nums.size();
        vector<int> diff(n+1,0);
        for(int i=0; i<k ; i++){
            auto q = queries[i];
            diff[q[0]]+=q[2];
            diff[q[1]+1]-=q[2];
        }
        int curr=0;
        for(int i=0; i<n; i++){
            curr += diff[i];
            if(nums[i] > curr){
                return false;
            }
        }
        return true;
    }
};
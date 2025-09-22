class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ans(n-k+1, -1);
        deque<int> mx;
        for(int r=0; r<n; r++){
            while(!mx.empty() && r-mx.front() >= k){
                mx.pop_front();
            }
            while(!mx.empty() && nums[mx.back()]<nums[r]){
                mx.pop_back();
            }
            mx.push_back(r);
            if(r-k+1>=0) ans[r-k+1] = nums[mx.front()];
        }
        return ans;
    }
};
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int ans=0, n=nums.size();
        for(auto &e: nums){
            ans += e&1;
        }
        int curr=0;
        for(auto &e: nums){
            curr += (e%2==0);
        }
        ans = max(ans, curr);
        curr=0;
        bool odd=true;
        for(int i=0; i<n; i++){
            if(nums[i]&1 && odd){
                curr++;
                odd = !odd;
            }else if(nums[i]%2==0 && !odd){
                curr++;
                odd = !odd;
            }
        }
        ans = max(ans, curr);
        curr=0;
        odd=false;
        for(int i=0; i<n; i++){
            if(nums[i]&1 && odd){
                curr++;
                odd = !odd;
            }else if(nums[i]%2==0 && !odd){
                curr++;
                odd = !odd;
            }
        }
        ans = max(curr, ans);
        return ans;
    }
};
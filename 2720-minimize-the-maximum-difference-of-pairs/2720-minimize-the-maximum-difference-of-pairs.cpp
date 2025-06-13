class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), l = 0, h = nums[n-1] - nums[0], mid;

        auto check = [&](){
            int i = 0, count = 0;
            while (i < n-1) {
                if (nums[i+1] - nums[i] <= mid) {
                    count++;
                    i++;
                }
                i++;
            }
            return count >= p;
        };

        while(l<h){
            mid = l + (h-l)/2;
            if(check()){
                h = mid;
            }else{
                l = mid+1;
            }
        }
        return l;
    }
};
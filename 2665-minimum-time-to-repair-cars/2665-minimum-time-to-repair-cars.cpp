class Solution {
public:
    long long repairCars(vector<int>& nums, int cars) {
        long long l = *min_element(nums.begin(), nums.end());
        long long r = *max_element(nums.begin(), nums.end());
        l = l * 1 * 1;
        r = r * cars * cars;
        int n=nums.size();
        while(l<r){
            long long mid = l+(r-l)/2;
            long long cnt=0;
            for(int i=0; i<n; i++){
                cnt += floor(sqrt( (mid*1.0)/nums[i] ));
                if(cnt>=cars) break;
            }
            if(cnt >= cars){
                r = mid;
            }else{
                l = mid+1;
            }
        }
        return r;
    }
};
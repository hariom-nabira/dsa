class Solution {
public:
    int minEatingSpeed(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int l=1, h=arr.back(), ans=h, mid;
        
        auto check = [&](){
            long long minReq = 0;
            for(auto &e:arr){
                minReq += ceil((1.0*e)/mid);
            }
            return minReq<=k;
        };
        
        while(l<=h){
            mid = l + (h-l)/2;
            if(check()){
                ans = mid;
                h = mid-1;
            }else{
                l = mid+1;
            }
        }
        return ans;
    }
};
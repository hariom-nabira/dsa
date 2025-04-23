class Solution {
public:
    int helper(int n){
        int ans=0;
        while(n>0){
            ans += n%10;
            n/=10;
        }
        return ans;
    }
    int countLargestGroup(int n) {
        vector<int> mp(37);
        int mx = INT_MIN, cnt=0;
        for(int i=1; i<=n; i++){
            int dgsum = helper(i);
            mp[dgsum]++;
        }
        for(auto &s: mp){
            if(s>=mx){
                if(s>mx)
                    cnt = 0;
                mx = s;
                cnt++;
            }
        }
        return cnt;
    }
};
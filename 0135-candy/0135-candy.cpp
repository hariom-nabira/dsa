class Solution {
public:
    int candy(vector<int>& a) {
        int n=a.size(), i=1, ans=n;
        while(i<n){
            if(a[i]==a[i-1]){
                i++; continue;
            }
            int currPeak=0;
            while(i<n && a[i]>a[i-1]){
                currPeak++;
                ans += currPeak;
                i++;
            }
            int currValley=0;
            while(i<n && a[i]<a[i-1]){
                currValley++;
                ans += currValley;
                i++;
            }
            ans -= min(currPeak, currValley);
        }
        return ans;
    }
};
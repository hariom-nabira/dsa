class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        meetings.push_back({days+1, days+1});
        int n=meetings.size();
        sort(meetings.begin(), meetings.end());
        vector<vector<int>> mergedIntervals;
        int l=0, r=0;
        for(int i=0; i<n; i++){
            if(meetings[i][0] <= r){
                l = min(l,meetings[i][0]);
                r = max(r,meetings[i][1]);
            }else{
                mergedIntervals.push_back({l,r});
                l = meetings[i][0];
                r = meetings[i][1];
            }
        }
        mergedIntervals.push_back({l,r});    
        // for(auto &v: mergedIntervals) cout<<v[0]<<" "<<v[1]<<"\n";
        int ans=0, sz=mergedIntervals.size();
        for(int i=1; i<sz; i++){
            ans += max(0, mergedIntervals[i][0]-mergedIntervals[i-1][1]-1);
        }
        return ans;
    }
};
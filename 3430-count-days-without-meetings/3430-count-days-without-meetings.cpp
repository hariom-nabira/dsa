//same logic, cleaner implementation
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int ans = 0;
        sort(meetings.begin(),meetings.end());
        ans += meetings[0][0]-1;
        int prevEnd = meetings[0][1];
        for(int i=1; i<meetings.size(); i++){
            if(meetings[i][0]>prevEnd){
                ans += meetings[i][0]-prevEnd-1; 
            }
            prevEnd = max(prevEnd,meetings[i][1]);
        }
        ans += days - prevEnd;
        return ans; 
    }
};
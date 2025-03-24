//same logic, much cleaner implementation (editorial)
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int freeDays = 0, latestEnd = 0;
        sort(meetings.begin(), meetings.end());
        for (auto& meeting : meetings) {
            if (meeting[0] > latestEnd + 1) {
                freeDays += meeting[0] - latestEnd - 1;
            }
            latestEnd = max(latestEnd, meeting[1]);
        }
        freeDays += days - latestEnd;
        return freeDays;
    }
};
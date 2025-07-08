//cfs

class Solution {
public:
    vector<vector<int>> dp;

    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        int n = events.size();
        dp.assign(k + 1, vector<int>(n, -1));
        return dfs(0, k, events);
    }

private:
    int dfs(int curIndex, int count, const vector<vector<int>>& events) {
        if (count == 0 || curIndex == events.size()) {
            return 0;
        }
        if (dp[count][curIndex] != -1) {
            return dp[count][curIndex];
        }
        int nextIndex = bisectRight(events, events[curIndex][1]);
        int skip = dfs(curIndex + 1, count, events);
        int take = events[curIndex][2] + dfs(nextIndex, count - 1, events);
        return dp[count][curIndex] = max(skip, take);
    }

    int bisectRight(const vector<vector<int>>& events, int target) {
        int left = 0, right = events.size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (events[mid][0] <= target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};

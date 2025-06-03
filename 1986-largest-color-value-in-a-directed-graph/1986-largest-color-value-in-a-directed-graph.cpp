class Solution {
private:
    int helper(int node, vector<vector<int>> &dp, vector<vector<int>> &mp, string &colors, vector<int> &visited){
        if(!visited[node]){
            visited[node] = 1;
            for(auto &ch:mp[node]){
                if(helper(ch,dp,mp,colors,visited)==INT_MAX) return INT_MAX;
                for(int c=0; c<26; c++){
                    dp[node][c] = max(dp[node][c], dp[ch][c]);
                }
            }
            dp[node][colors[node]-'a']++;
            visited[node] = 2;
        }
        return visited[node]==2? dp[node][colors[node]-'a']:INT_MAX;
    }
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> mp(n), dp(n, vector<int>(26));
        vector<int> visited(n);
        for(auto &e: edges){
            mp[e[0]].push_back(e[1]);
        }
        int ans=0;
        for(int i=0; i<n && ans!=INT_MAX; i++){
            ans = max(ans, helper(i,dp,mp,colors,visited));
        }
        return (ans==INT_MAX)? -1:ans;
    }
};
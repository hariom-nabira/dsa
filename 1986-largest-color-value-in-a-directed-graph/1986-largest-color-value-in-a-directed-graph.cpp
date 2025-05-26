class Solution {
private:
    int helper(int node, int color, vector<vector<int>> &dp, vector<vector<int>> &mp, string &colors){
        if(dp[node][color]!=-1) return dp[node][color];
        int ans = 0;
        for(auto &ch : mp[node]){
            ans = max(ans, helper(ch,color,dp,mp,colors));
        }
        if(colors[node] == ('a'+color)) ans++;
        return dp[node][color] = ans;
    }
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> mp(n);
        vector<int> inDeg(n);
        for(auto &e: edges){
            mp[e[0]].push_back(e[1]);
            inDeg[e[1]]++;
        }
        int ans=0, done=0;
        queue<int> q;
        for(int i=0; i<n; i++){
            if(!inDeg[i]){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            done++;
            for(auto &c: mp[node]){
                if(--inDeg[c]==0){
                    q.push(c);
                }
            }
        }
        if(done!=n) return -1;
        vector<vector<int>> dp(n, vector<int>(26, -1));
        for(int i=0; i<n; i++){
            for(int c=0; c<26; c++){
                ans = max(ans, helper(i,c,dp,mp,colors));
            }
        }
        return ans;
    }
};
class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = candies.size(), ans=0;
        vector<bool> found(n);
        queue<int> q;
        for(auto &b : initialBoxes){
            found[b] = true;
            if(status[b]){
                q.push(b);
                ans += candies[b];
                candies[b] = 0;
            }
        }
        while(!q.empty()){
            int box = q.front(); q.pop();
            for(auto b: keys[box]){
                status[b] = 1;
                if(found[b] && candies[b]){
                    q.push(b);
                    ans += candies[b];
                    candies[b] = 0;
                }
            }
            for(auto b: containedBoxes[box]){
                found[b] = true;
                if(status[b] && candies[b]){
                    q.push(b);
                    ans += candies[b];
                    candies[b] = 0;
                }
            }
        }
        return ans;
    }
};
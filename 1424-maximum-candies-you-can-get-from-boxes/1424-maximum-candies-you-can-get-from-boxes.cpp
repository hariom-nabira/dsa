class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = candies.size(), ans=0;
        vector<bool> found(n);
        for(auto &b : initialBoxes) found[b] = true;
        queue<int> q;
        for(int i=0; i<n; i++){
            if(found[i] && status[i]) q.push(i);
        }
        while(!q.empty()){
            int box = q.front(); q.pop();
            if(!candies[box]) continue;
            ans += candies[box];
            candies[box] = 0;
            for(auto b: keys[box]){
                status[b] = 1;
                if(found[b] && candies[b]) q.push(b);
            }
            for(auto b: containedBoxes[box]){
                found[b] = true;
                if(status[b] && candies[b]) q.push(b);
            }
        }
        return ans;
    }
};
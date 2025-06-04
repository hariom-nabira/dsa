class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, vector<int>> xMap(n+1), yMap(n+1);
        for(auto &b: buildings){
            xMap[b[0]].push_back(b[1]);
            yMap[b[1]].push_back(b[0]);
        }
        for(auto &[x,v]: xMap) sort(v.begin(), v.end());
        for(auto &[y,v]: yMap) sort(v.begin(), v.end());
        
        int ans=0;
        for(auto &b: buildings){
            int x=b[0], y=b[1];
            if(y==xMap[x].front() || y==xMap[x].back() || x==yMap[y].front() || x==yMap[y].back()) continue;
            ans++;
        }
        return ans;
    }
};
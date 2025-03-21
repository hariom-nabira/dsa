class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        map<string, vector<string>> graph;
        map<string, int> indegree;
        // set<string> reci(recipes.begin(), recipes.end());
        for(int i=0; i<n; i++){
            for(auto &ing: ingredients[i]){
                graph[ing].push_back(recipes[i]);
                indegree[recipes[i]]++;
            }
        }
        vector<string> ans;
        queue<string> q; //(supplies.begin(), supplies.end())
        for(auto &s: supplies){
            for(auto &o: graph[s]){
                indegree[o]--;
                if(!indegree[o]){
                    q.push(o);
                }
            }
        }
        while(!q.empty()){
            string s = q.front();
            q.pop();
            // if(reci.count(s)){
                ans.push_back(s);
            // }
            for(auto &o: graph[s]){
                indegree[o]--;
                if(!indegree[o]){
                    q.push(o);
                }
            }
        }
        return ans;
    }
};
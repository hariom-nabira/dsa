class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<int> parent(n,0);
        vector<int> cost(n,INT_MAX);
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
        for(auto &e: edges){
            myUnion(e[0], e[1], e[2], parent, cost);
        }
        for(int i=0; i<n; i++){
            cout<<"Cost of "<<i<<" -----> "<<cost[i]<<"\n";
        }
        vector<int> ans;
        for(auto &q: query){
            int irep = find(q[0], parent);
            if(irep != find(q[1], parent)){
                ans.push_back(-1);
            }else{
                ans.push_back(cost[irep]);
            }
        }
        return ans;
    }
private:
    int find(int i, vector<int> &parent) {
        int par = parent[i];
        if (parent[par] != par) {
            return parent[par] = find(par, parent);
        }
        return par;
    }
    void myUnion(int i, int j, int w, vector<int> &parent, vector<int> &cost) {
        int irep = find(i, parent);
        int jrep = find(j, parent);
        if(irep==jrep){
            cost[irep] &= w;
            return;
        }
        parent[irep] = jrep;
        cost[jrep] &= cost[irep];
        cost[jrep] &= w;
        cost[irep] = -1;
    }
};
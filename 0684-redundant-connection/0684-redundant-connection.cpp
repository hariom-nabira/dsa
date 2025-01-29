class Solution {
public:
    int find(int u, vector<int> &parent){
        if(parent[u]==u) return u;
        return find(parent[u], parent);
    }
    void unionH(int u, int v, vector<int> &parent){
        parent[find(v, parent)] = find(u, parent);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& v) {
        int n = v.size();
        vector<int> parent(n);
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
        for(int i=0; i<n; i++){
            if(find(v[i][0]-1, parent)==find(v[i][1]-1, parent)){
                return v[i];
            }
            unionH(v[i][0]-1, v[i][1]-1, parent);
        }
        return {};
    }
};
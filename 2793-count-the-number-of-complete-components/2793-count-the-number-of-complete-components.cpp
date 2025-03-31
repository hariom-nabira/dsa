class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        par.resize(n, -1);
        size.resize(n, 1);
        edgesInComponent.resize(n, 0);
        for(auto &e: edges){
            myUnion(e[0], e[1]);
        }
        int ans=0;
        for(int i=0; i<n; i++){
            if(size[i] && edgesInComponent[i]==((size[i]*(size[i]-1))/2)) ans++;
        }
        return ans;
    }
private:
    vector<int> par, size, edgesInComponent;
    int find(int i){
        if(par[i]==-1) return i;
        return par[i] = find(par[i]);
    }
    void myUnion(int x, int y){
        int r1 = find(x), r2 = find(y);
        if(size[r1]<size[r2]) swap(r1,r2);
        edgesInComponent[r1]++;
        if(r1==r2) return;
        edgesInComponent[r1] += edgesInComponent[r2];
        size[r1] += size[r2];
        size[r2]=0;
        par[r2] = r1;
    }
};
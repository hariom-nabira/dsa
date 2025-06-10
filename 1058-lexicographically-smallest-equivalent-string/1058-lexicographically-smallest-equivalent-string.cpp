class UnionFind {
private:
    vector<int> par;
public:
    UnionFind(int n){
        par.resize(n);
        iota(par.begin(), par.end(), 0);
    }
    int myFind(int a){
        if(par[a]==a) return a;
        return par[a] = myFind(par[a]);
    }
    void myUnion(int a, int b){
        int pa = myFind(a);
        int pb = myFind(b);
        if(pa>pb){
            par[pa] = pb;
        }else{
            par[pb] = pa;
        }
    }
};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n=s1.size();
        UnionFind uf(26);
        for(int i=0; i<n; i++){
            uf.myUnion(s1[i]-'a', s2[i]-'a');
        }
        string ans="";
        for(auto &ch: baseStr){
            ans += ('a' + uf.myFind(ch-'a'));
        }
        return ans;
    }
};
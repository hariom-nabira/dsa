class Solution {
private:
    int myFind(vector<int> &par, int a){
        if(par[a]==-1) return a;
        return par[a] = myFind(par, par[a]);
    }
    void myUnion(vector<int> &par, int a, int b){
        if(myFind(par,a) == myFind(par,b)) return;
        par[myFind(par,a)] = b;
    }
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> par(26,-1);
        int n=s1.size();
        for(int i=0; i<n; i++){
            myUnion(par, s1[i]-'a', s2[i]-'a');
            cout<<"------------ "<<s1[i]<<" "<<s2[i]<<"\n";
        }
        string ans="";
        for(auto &ch: baseStr){
            int req = myFind(par, ch-'a');
            for(int c=0; c<26; c++){
                if(myFind(par,c) == req){
                    ans += ('a'+c);
                    break;
                }
            }
        }
        return ans;
    }
};
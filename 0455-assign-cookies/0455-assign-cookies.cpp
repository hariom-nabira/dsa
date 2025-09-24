class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int p=g.size(), t=s.size(), ans=0, i=0, j=0;
        while(i<p && j<t){
            if(s[j] >= g[i]){
                i++; ans++;
            }
            j++;
        }
        return ans;
    }
};
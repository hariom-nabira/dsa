class Solution {
public:
    string clearStars(string s) {
        int n=s.size();
        vector<vector<int>> pos(26, vector<int>());
        for(int i=0; i<n; i++){
            if(s[i]!='*'){
                pos[s[i]-'a'].push_back(i);
            }else{
                for(int c=0; c<26; c++){
                    if(pos[c].size()){
                        s[pos[c].back()] = '*';
                        pos[c].pop_back();
                        break;
                    }
                }
            }
        }
        string ans="";
        for(int i=0; i<n; i++){
            if(s[i]!='*') ans += s[i];
        }
        return ans;
    }
};
class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        while(s.size()%k){
            s += fill;
        }
        int i=0, n=s.size();
        vector<string> ans;
        while(i<n){
            ans.push_back(s.substr(i,k));
            i+=k;
        }
        return ans;
    }
};
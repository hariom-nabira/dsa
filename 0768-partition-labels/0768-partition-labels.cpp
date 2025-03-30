class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char,int> last;
        int n=s.size();
        for(int i=0; i<n; i++) last[s[i]] = i;
        vector<int> ans;
        int start, end, open=0;
        for(int i=0; i<n; i++){
            if(!open){
                end = last[s[i]];
                start=i;
                open=1; 
            }
            if(i==end){
                ans.push_back(end-start+1);
                open=0;
            }else{
                end = max(end, last[s[i]]);
            }
        }
        return ans;
    }
};
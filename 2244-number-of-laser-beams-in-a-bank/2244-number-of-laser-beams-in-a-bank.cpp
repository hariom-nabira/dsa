class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> cnts;
        for(auto &s: bank){
            int cnt = 0;
            for(auto &ch: s) cnt += (ch=='1');
            if(cnt) cnts.push_back(cnt);
        }
        int n=cnts.size(), ans=0;
        for(int i=1; i<n; i++){
            ans += cnts[i]*cnts[i-1];
        }
        return ans;
    }
};
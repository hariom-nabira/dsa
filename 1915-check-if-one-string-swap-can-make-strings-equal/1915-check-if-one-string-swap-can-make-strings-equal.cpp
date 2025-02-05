class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size(), cnt=0, last=-1;
        for(int i=0; i<n; i++){
            if(s1[i]!=s2[i]){
                cnt++;
                if(cnt>2) return false;
                if(cnt==1){
                    last = i;
                }else if(cnt==2){
                    if(s1[i]!=s2[last] || s2[i]!=s1[last]) return false;
                }
            }
        }
        return cnt!=1;
    }
};
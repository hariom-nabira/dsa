class Solution {
public:
    string lastSubstring(string s) {
        int i=0, j=1, n=s.size();
        // while(j<n){
            int k=0;
            while(j+k < n){
                if(s[i+k] > s[j+k]){
                    j = max(j+1, i+k+1);
                    k=0;
                }else if(s[i+k] < s[j+k]){
                    i = max(i+k+1,j);
                    j = i+1;
                    k=0;
                }else{
                    k++;
                }
            }
            // j = i+1;
            // while(j<n && s[j]!=s[i]) j++;
        // }
        return s.substr(i);
    }
};
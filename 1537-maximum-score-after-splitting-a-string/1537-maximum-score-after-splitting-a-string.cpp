class Solution {
public:
    int maxScore(string s) {
        int ones=0;
        for(char &ch:s) if(ch=='1') ones++;
        int zeroes = 0, n=s.size();
        int ans = INT_MIN;
        for(int i=0; i<n-1; i++){
            if(s[i]=='0'){
                zeroes++;
            }else{
                ones--;
            }
            ans = max(ans, zeroes+ones);
        }
        return ans;
    }
};
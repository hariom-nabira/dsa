class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diff(n);
        for(auto &sh : shifts){
            if(sh[2]){
                diff[sh[0]]++;
                if(sh[1]<n-1) diff[sh[1]+1]--;
            }else{
                diff[sh[0]]--;
                if(sh[1]<n-1) diff[sh[1]+1]++;
            }
        }
        int sh = 0;
        for(int i=0; i<n; i++){
            sh = (sh + diff[i])%26;
            s[i] = (char)('a' + ( s[i]-'a'+ sh + 26) % 26);
        }
        return s;
    }
};
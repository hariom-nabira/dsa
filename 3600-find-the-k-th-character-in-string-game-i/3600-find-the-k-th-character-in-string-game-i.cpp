class Solution {
public:
    char kthCharacter(int k) {
        string s = "a";
        while(s.size() < k){
            int n=s.size();
            for(int i=0; i<n; i++){
                s += 'a' + (s[i]-'a'+1)%26;
            }
        }
        return s[k-1];
    }
};
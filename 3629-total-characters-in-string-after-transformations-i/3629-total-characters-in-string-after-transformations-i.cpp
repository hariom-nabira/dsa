class Solution {
private:
    int MOD = 1e9 + 7;
public:
    int lengthAfterTransformations(string s, int t) {
        vector<int> freq(26);
        for(auto &c:s) freq[c-'a']++;
        while(t--){
            vector<int> next(26);
            for(int i=1; i<26; i++){
                next[i] = freq[i-1];
            }
            next[0] = freq[25];
            next[1] += freq[25];
            freq = next;
        }
        int ans=0;
        for(int i=0; i<26; i++){
            ans = (ans + freq[i]) % MOD;
        }
        return ans;
    }
};
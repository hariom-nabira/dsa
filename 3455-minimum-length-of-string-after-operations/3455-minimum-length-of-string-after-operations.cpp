//cfs

class Solution {
public:
    int minimumLength(string s) {
        vector<int> freq(26);
        for (char ch : s) {
            freq[ch-'a']++;
        }
        int ans = 0;
        for (auto &f: freq) {
            ans += (f&1)? 1 : (f>0)? 2:0;
        }
        return ans;
    }
};
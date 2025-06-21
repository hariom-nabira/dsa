class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26);
        for(auto &ch: word) freq[ch-'a']++;
        int ans = word.size()+1;
        for(auto &a: freq){
            int curr=0;
            for(auto &b: freq){
                if(b < a){
                    curr += b;
                }else if(b > a+k){
                    curr += b - (a+k);
                }
            }
            ans = min(ans, curr);
        }
        return ans;
    }
};
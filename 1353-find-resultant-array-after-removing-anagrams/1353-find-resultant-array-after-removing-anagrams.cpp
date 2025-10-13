class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();
        vector<int> freqPrev(26);
        vector<string> ans;
        ans.push_back(words[0]);
        for(auto &e: words[0]) freqPrev[e-'a']++;
        for(int i=1; i<n; i++){
            vector<int> freqCurr(26);
            for(auto &e: words[i]) freqCurr[e-'a']++;
            if(freqPrev != freqCurr){
                ans.push_back(words[i]);
                freqPrev = freqCurr;
            }
        }
        return ans;
    }
};
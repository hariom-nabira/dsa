class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> freqB(26);
        for(auto &str: words2){
            vector<int> tempFreq(26);
            for(auto &ch: str){
                tempFreq[ch-'a']++;
            }
            for(int i=0; i<26; i++){
                freqB[i] = max(freqB[i], tempFreq[i]);
            }
        }
        vector<string> ans;
        for(auto &str : words1){
            vector<int> tempFreq(26);
            for(auto &ch: str){
                tempFreq[ch-'a']++;
            }
            bool flag = 1;
            for(int i=0; i<26; i++){
                if(tempFreq[i] < freqB[i]){
                    flag = false;
                    break;
                }
            }
            if(flag) ans.push_back(str);
        }
        return ans;
    }
};
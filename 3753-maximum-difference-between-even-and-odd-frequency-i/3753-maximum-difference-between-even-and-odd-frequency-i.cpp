class Solution {
public:
    int maxDifference(string s) {
        vector<int> freq(26);
        int oddMax=INT_MIN, evenMin=INT_MAX;
        for(auto &ch: s) freq[ch-'a']++;
        for(int i=0; i<26; i++){
            if(!freq[i]) continue;
            if(freq[i]%2==1){
                oddMax = max(oddMax, freq[i]);
            } 
            else{
                evenMin = min(evenMin, freq[i]);
            } 
        }
        return oddMax-evenMin;
    }
};
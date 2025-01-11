class Solution {
public:
    bool canConstruct(string s, int k) {
        vector<int> freq(26);
        for(auto &ch: s){
            freq[ch-'a']++;
        }
        int odds=0;
        for(int i=0; i<26; i++){
            if(freq[i]&1) odds++;
        }
        return (s.size()>=k && odds<=k); 
    }
};
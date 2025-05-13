class Solution {
private:
    int MOD = 1e9 + 7;
    void helper(vector<int> &freqA, vector<int> &freqB, bool &inA){
        for(int i=0; i<25; i++){
            if(inA){
                freqB[i+1] = freqA[i];
                freqA[i] = 0;
            }else{
                freqA[i+1] = freqB[i];
                freqB[i] = 0;
            }
        }
        if(inA){
            freqB[0] = freqA[25];
            freqB[1] = (freqB[1] + freqB[0]) % MOD;
            freqA[25] = 0;
        }else{
            freqA[0] = freqB[25];
            freqA[1] = (freqA[1] + freqA[0]) % MOD;
            freqB[25] = 0;
        }
        inA = !inA;
    }
public:
    int lengthAfterTransformations(string s, int t) {
        vector<int> freqA(26), freqB(26);
        for(auto &c:s) freqA[c-'a']++;
        bool inA = true;
        while(t--){
            helper(freqA, freqB, inA);
            // for(int i=0; i<26; i++){
            //     cout<<freqA[i]<<" "<<freqB[i]<<"\n";
            // }
            // cout<<"==================================\n";
        }
        int ans=0;
        for(int i=0; i<26; i++){
            if(inA){
                // cout<<freqA[i]<<" ";
                ans = (ans + freqA[i]) % MOD;
            }else{
                // cout<<freqB[i]<<" ";
                ans = (ans + freqB[i]) % MOD;
            }
        }
        return ans;
    }
};
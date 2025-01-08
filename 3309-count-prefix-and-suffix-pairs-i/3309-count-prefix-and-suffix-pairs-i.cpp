class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans=0, n=words.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int n1 = words[i].size(), n2=words[j].size();
                if(n2>=n1 && words[j].substr(0,n1)==words[i] && words[j].substr(n2-n1,n1)==words[i]){
                    ans++;
                }
            }
        }
        return ans;
    }
};
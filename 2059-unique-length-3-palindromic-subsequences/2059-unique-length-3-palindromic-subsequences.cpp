class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size(), ans=0;
        unordered_set<char> usedStartChar;
        vector<vector<int>> charOccurences(26,vector<int>());
        for(int i=0; i<n; i++){
            charOccurences[s[i]-'a'].push_back(i);
        }
        for(int i=0; i<n; i++){
            if(usedStartChar.contains(s[i])) continue;
            int lastOccurence = charOccurences[s[i]-'a'].back();
            if(lastOccurence > i){
                for(int j=0; j<26; j++){
                    if(helper(charOccurences[j], i+1,lastOccurence-1)){
                        ans++;
                        // cout<<i<<" "<<j<<"\n";
                    }
                }
            }
            usedStartChar.insert(s[i]);
        }
        return ans;
    }
    bool helper(vector<int> &occurences, int low, int high){
        auto it = lower_bound(occurences.begin(), occurences.end(), low);
        if(it != occurences.end() && *it <= high) return true;
        return false;
    }
};
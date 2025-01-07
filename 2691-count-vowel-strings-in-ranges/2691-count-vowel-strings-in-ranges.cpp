class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size();
        set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        vector<int> pre(n+1);
        for(int i=1; i<=n; i++){
            pre[i] = pre[i-1];
            if(vowels.contains(words[i-1][0]) && vowels.contains(*(words[i-1].rbegin()))){
                pre[i]++;
            }
        }
        vector<int> ans;
        for(auto q: queries){
            ans.push_back(pre[q[1]+1] - pre[q[0]]);
        }
        return ans;
    }
};
class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        for(auto s: words){
            for(auto str: words){
                if(str==s) continue;
                if(str.find(s) != string::npos){
                    ans.push_back(s);
                    break;
                }
            }
        }
        return ans;
    }
};
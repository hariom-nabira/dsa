class Solution {
private:
    unordered_map<int, vector<char>> mp;
    
    void helper(vector<string> &ans, string &curr, string &arr, int start){
        if(start==arr.size()){
            ans.push_back(curr);
            return;
        }
        if(arr[start]<2) helper(ans, curr, arr, start+1);
        for(auto &ch: mp[arr[start]-'0']){
            curr.push_back(tolower(ch));
            helper(ans, curr, arr, start+1);
            curr.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(!digits.size()) return {};
        mp = {
            {2, {'A', 'B', 'C'}},
            {3, {'D', 'E', 'F'}},
            {4, {'G', 'H', 'I'}},
            {5, {'J', 'K', 'L'}},
            {6, {'M', 'N', 'O'}},
            {7, {'P' ,'Q', 'R', 's'}},
            {8, {'T', 'U', 'V'}},
            {9, {'W', 'X', 'Y', 'Z'}}
        };
        vector<string> ans;
        string curr = "";
        helper(ans, curr, digits, 0);
        return ans;
    }
};
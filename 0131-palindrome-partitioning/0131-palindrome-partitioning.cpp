class Solution {
private:
    unordered_map<int, vector<vector<string>>> memo;
    vector<vector<bool>> isPalindrome;

    vector<vector<string>> helper(string s, int i){
        int n = s.size();
        if(i==n) return {{}};
        if(memo.find(i) != memo.end()) return memo[i];
        vector<vector<string>> ans;
        for(int j=i; j<n; j++){
            if(isPalindrome[i][j]){
                for(auto &path : helper(s, j+1)){
                    // {substring(i to j) + path}
                    vector<string> newPath = {s.substr(i, j-i+1)};
                    newPath.insert(newPath.end(), path.begin(), path.end());
                    ans.push_back(newPath);
                    
                    // this works too, is slightly more space optimised as it doesn't create newPath vector

                    // ans.emplace_back();
                    // ans.back().push_back(s.substr(i, j-i+1));
                    // ans.back().insert(ans.back().end(), path.begin(), path.end());
                }
            }
        }
        return memo[i] = ans;
    }
public:
    vector<vector<string>> partition(string s) {
        int n=s.size();
        isPalindrome = vector(n, vector<bool>(n));
        for(int i=0; i<n; i++){
            isPalindrome[i][i] = true;
        }
        for(int length=2; length<=n; length++){
            for(int i=0; i<=n-length; i++){
                int j=i+length-1;
                if(s[i]==s[j] && (length==2 || isPalindrome[i+1][j-1]==true)){
                    isPalindrome[i][j] = true;
                }else{
                    isPalindrome[i][j] = false;
                }
            }
        }
        return helper(s,0);
    }
};
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> mp;
        for(auto &w: words) mp[w]++;
        int ans=0;
        bool odd = false;
        while(!mp.empty()){
            string curr = mp.begin()->first;
            if(curr[0]==curr[1]){
                if(mp[curr]&1) odd = true;
                ans += 2*(mp[curr]/2);
                mp.erase(curr);
                continue;
            }
            string reverse(curr.rbegin(), curr.rend());
            ans += 2*min(mp[curr], mp[reverse]);
            mp.erase(curr);
            mp.erase(reverse);
        }
        if(odd)ans++;
        return ans*2;
    }
};
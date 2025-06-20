class Solution {
private:
    int helper(string &s, int k, char v, char h){
        int ans=0, dist=0;
        for(auto &ch : s){
            if(ch==v || ch==h || k-- >0){
                dist++;
                ans = max(ans, dist);
            }else{
                dist--;
            }
        }
        return ans;
    }
public:
    int maxDistance(string s, int k) {
        int ans = INT_MIN;
        ans = max(ans, helper(s, k, 'N', 'E'));
        ans = max(ans, helper(s, k, 'N', 'W'));
        ans = max(ans, helper(s, k, 'S', 'E'));
        ans = max(ans, helper(s, k, 'S', 'W'));
        return ans;
    }
};
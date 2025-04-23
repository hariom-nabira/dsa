class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int fl=0, n=encoded.size()+1;
        for(auto &e:encoded) fl ^= e;
        vector<int> ans(n);
        ans[0] = fl;
        for(int i=1; i<n; i++){
            ans[i] = (ans[i-1] ^ encoded[i-1]);
        }
        int last = 0;
        for(int i=0; i<n; i++){
            last ^= ans[i];
            last ^= (i+1);
        }
        for(auto &e: ans){
            e ^= last;
        }
        return ans;
    }
};
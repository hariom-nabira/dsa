class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n=derived.size(), ans=0;
        for(int i = n-1; i>=0; i--){
            ans ^= derived[i];
        }
        return !ans;
    }
};
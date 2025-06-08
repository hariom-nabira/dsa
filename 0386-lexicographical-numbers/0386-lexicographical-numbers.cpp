//cfs
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int start = 1;start<=9;start++)
            helper(start,n,ans);
        return ans;
    }
    void helper(int num, int &n, vector<int> &ans){
        if(num > n) return;
        ans.push_back(num);
        for(int i=0;i<=9;i++){
            if(num*10 + i > n) return;
            helper(num*10+i,n,ans);
        }
    }
};
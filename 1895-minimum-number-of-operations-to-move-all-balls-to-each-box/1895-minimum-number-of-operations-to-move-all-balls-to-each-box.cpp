class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size(), curr=0;
        vector<int> ans(n), pre(n+1);
        for(int i=0; i<n; i++){
            pre[i+1] = pre[i] + curr;
            ans[i] += pre[i+1];
            curr += (boxes[i]=='1');
        }
        curr = 0;
        fill(pre.begin(),pre.end(),0);
        for(int i=n-1; i>=0; i--){
            pre[i] = pre[i+1] + curr;
            ans[i] += pre[i];
            curr += (boxes[i]=='1');
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int curr = 0, n = A.size();
        vector<int> freq(n+1), ans(n);
        for(int i=0; i<n; i++){
            if(freq[A[i]]++) curr++;
            if(freq[B[i]]++) curr++;
            ans[i] = curr;
        }
        return ans;
    }
};
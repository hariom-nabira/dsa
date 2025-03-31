class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        // long long mn = weights[0]+weights[n-1];
        // long long mx = mn; (since they get cancelled out anyways when mx-mn)
        long long ans=0;
        for(int i=0; i<n-1; i++) weights[i] += weights[i+1];
        weights.pop_back();
        sort(weights.begin(), weights.end());
        for(int i=0; i<k-1; i++){
            ans -= weights[i];
            ans += weights[n-2-i];
        }
        return ans;
    }
};
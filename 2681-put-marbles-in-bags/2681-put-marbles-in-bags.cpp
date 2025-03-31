class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        long long mn = weights[0]+weights[n-1];
        long long mx = mn;
        vector<long long> options;
        for(int i=0; i<n-1; i++) options.push_back(weights[i]+weights[i+1]);
        sort(options.begin(), options.end());
        for(int i=0; i<k-1; i++){
            mn += options[i];
            mx += options[n-2-i];
        }
        return mx-mn;
    }
};
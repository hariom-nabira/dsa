class Solution {
public:
    vector<int> overlap(vector<int> &a, vector<int> &b){
        return {max(a[0],b[0]), min(a[1], b[1])};
    }
    int countArrays(vector<int>& original, vector<vector<int>>& bounds) {
        vector<int> currRange = bounds[0];
        int n = original.size();
        for(int i=1; i<n; i++){
            int diff = original[i] - original[i-1];
            vector<int> requiredRange = currRange;
            requiredRange[0] += diff;
            requiredRange[1] += diff;
            currRange = overlap(requiredRange, bounds[i]);
            if(currRange[1]<currRange[0]) return 0;
        }
        return currRange[1] - currRange[0] + 1;
    }
};
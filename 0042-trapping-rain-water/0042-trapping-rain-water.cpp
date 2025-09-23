class Solution {
public:
    int trap(vector<int>& heights) {
        int n=heights.size();
        vector<int> preMax(n+1), suffMax(n+1);
        for(int i=0; i<n; i++){
            preMax[i+1] = max(preMax[i], heights[i]);
            suffMax[n-i-1] = max(suffMax[n-i], heights[n-i-1]);
        }
        int ans=0;
        for(int i=1; i<n-1; i++){
            ans += max(0, min(preMax[i], suffMax[i+1])-heights[i]);
        }
        return ans;
    }
};
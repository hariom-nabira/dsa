class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxDiagSq = 0;
        int maxArea = INT_MIN;
        for(auto &r: dimensions){
            int temp = (r[0]*r[0] + r[1]*r[1]);
            if(temp >= maxDiagSq){
                maxArea = (temp > maxDiagSq)? r[0]*r[1]: max(maxArea, r[0]*r[1]);
                maxDiagSq = temp;
            }
        }
        return maxArea;
    }
};
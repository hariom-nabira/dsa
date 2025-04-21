class Solution {
public:
    int numberOfArrays(vector<int>& differences, int low, int high) {
        int currL=low, currH=high, ans = high-low+1;
        for(auto &d: differences){
            currL += d;
            currH += d;
            if(currL < low){
                ans -= low-currL;
                currL = low;
            }
            if(currH > high){
                ans -= currH - high;
                currH = high;
            }
            if(ans <= 0) return 0;
        }
        return ans;
    }
};
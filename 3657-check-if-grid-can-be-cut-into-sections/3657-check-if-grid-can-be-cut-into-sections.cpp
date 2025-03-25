class Solution {
public:
    static bool mySortX(vector<int> &a, vector<int> &b) {
        if(a[0]==b[0]) return a[2]<b[2];
        return a[0] < b[0];
    }
    static bool mySortY(vector<int> &a, vector<int> &b) {
        if(a[1]==b[1]) return a[3]<b[3];
        return a[1] < b[1];
    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        sort(rectangles.begin(), rectangles.end(), mySortX);
        int count=0, maxSoFar = rectangles[0][2];
        for(int i=1; i<(int) rectangles.size(); i++){
            if(rectangles[i][0] >= maxSoFar) count++;
            maxSoFar = max(maxSoFar, rectangles[i][2]);
        }
        if(count>=2) return true;

        sort(rectangles.begin(), rectangles.end(), mySortY);
        count=0, maxSoFar = rectangles[0][3];
        for(int i=1; i<(int) rectangles.size(); i++){
            if(rectangles[i][1] >= maxSoFar) count++;
            maxSoFar = max(maxSoFar, rectangles[i][3]);
        }
        if(count>=2) return true;
        return false;
    }
};
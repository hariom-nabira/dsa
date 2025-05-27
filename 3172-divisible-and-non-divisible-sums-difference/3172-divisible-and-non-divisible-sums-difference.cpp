class Solution {
public:
    int differenceOfSums(int n, int m) {
        int total = (n*(n+1))/2;
        int divM = m*((n/m)*(n/m +1)/2);
        return total - 2*divM;
    }
};
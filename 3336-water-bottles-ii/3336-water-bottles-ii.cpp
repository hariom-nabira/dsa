class Solution {
public:
    int maxBottlesDrunk(int nb, int ne) {
        int a = 1, b = 2*ne-3, c = -2*nb;
        int d = b*b - 4*a*c;
        int t = ceil((-b + sqrt(d))/(2*a));
        return nb+t-1;
    }
};
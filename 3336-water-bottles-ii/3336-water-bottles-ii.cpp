class Solution {
public:
    int maxBottlesDrunk(int nb, int ne) {
        int ans = nb, empty = nb;
        while(empty >= ne){
            empty -= (ne-1);
            ne++; 
            ans++;
        }
        return ans;
    }
};
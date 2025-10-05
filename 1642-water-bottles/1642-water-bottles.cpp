class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles, empty = numBottles;
        while(empty>=numExchange){
            ans += empty/numExchange;
            empty = empty%numExchange + empty/numExchange;
        }
        return ans;
    }
};
class Solution {
public:
    int setBits(int n){
        int ans=0;
        while(n>0){
            ans += n&1;
            n>>=1;
        }
        return ans;
    }
    int minimizeXor(int num1, int num2) {
        int diff = setBits(num2) - setBits(num1), moo = 0;
        for(int i=0; diff!=0 ;i++){
            if(diff>0 && !(num1&(1<<i))){
                moo += 1<<i;
                diff--;
            }else if(diff<0 && num1&(1<<i)){
                moo += 1<<i;
                diff++;
            }
        }
        return num1^moo;
    }
};
class Solution {
private:
    bool isSymetric(int n){
        int copy=n, noOfDigits=0;
        while(copy>0){
            noOfDigits++;
            copy/=10;
        }
        if(noOfDigits & 1) return false;
        noOfDigits/=2;
        int sum=0;
        while(noOfDigits--){
            sum+=n%10;
            n/=10;
        }
        while(n>0){
            sum-=n%10;
            n/=10;
        }
        return sum==0;
    }
public:
    int countSymmetricIntegers(int low, int high) {
        int ans=0;
        for(int i=low; i<=high; i++){
            ans += isSymetric(i);
        }
        return ans;
    }
};
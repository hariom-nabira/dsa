class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int n=ceil(log2(k)), shift=0;
        for(int i=n-1; i>=0; i--){
            if(k > (1LL<<i)){
                shift += operations[i];
                k -= (1LL << i);
            }
        }
        return 'a' + (shift)%26;
    }
};
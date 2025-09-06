class Solution {
private:
    long long helper(int n){
        if(n<=0) return 0;
        int temp = (log(n)*1.0)/log(4);
        long long ans=0;
        for(int i=1; i<=temp; i++){
            ans += (pow(4,i) - pow(4,i-1)) * i;
        }
        ans += (n - pow(4,temp) + 1) * (temp+1);
        return ans;
    }
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long ans = 0;
        for(auto &q: queries){
            ans += (helper(q[1]) - helper(q[0]-1) + 1)/2;
        }
        return ans;
    }
};
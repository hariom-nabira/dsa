class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int ans=0;
        for(auto &e: nums) if(e%2==0) ans|=e;
        return ans;
    }
};
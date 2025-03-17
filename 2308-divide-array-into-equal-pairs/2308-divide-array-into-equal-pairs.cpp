class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<int> freq(501);
        for(auto &e: nums) freq[e]++;
        for(auto &p:freq){
            if(p&1) return false;
        }
        return true;
    }
};
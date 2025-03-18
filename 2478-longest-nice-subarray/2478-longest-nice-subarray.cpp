class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int l=0, n=nums.size(), ans=1;
        map<int, int> bitPosFreq;
        for(int r=0; r<n; r++){
            //adding nums[r] to curr
            int temp = nums[r], bit=0;
            while(temp>0){
                if(temp&1){
                    bitPosFreq[bit]++;
                }
                temp>>=1;
                bit++;
            }
            //shrinking the window by removing nums[l] from curr
            while(!isValid(bitPosFreq)){
                int temp = nums[l++], bit=0;
                while(temp>0){
                    if(temp&1){
                        bitPosFreq[bit]--;
                    }
                    temp>>=1;
                    bit++;
                }
            }
            //updating ans
            ans = max(ans, r-l+1);
        }
        return ans;
    }
private:
    bool isValid(map<int,int> &mp){
        for(auto &p:mp){
            if(p.second>1) return false;
        }
        return true;
    }
};
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int ans=INT_MAX, currBlack=0, currCost=0;
        int l=0, n=blocks.size();
        for(int r=0; r<n; r++){
            if(blocks[r]=='W'){
                currCost++;
            }
            currBlack++;

            if(currBlack==k){
                ans = min(ans, currCost);
                currCost -= (blocks[l++]=='W')?1:0;
                currBlack--;
            }
        }
        return ans;
    }
};
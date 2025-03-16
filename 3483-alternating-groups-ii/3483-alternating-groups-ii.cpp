class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n=colors.size();
        int currLen=1, ans=0;
        for(int i=1; i<n+k-1; i++){
            if(colors[i%n]==colors[(i-1) %n]){
                currLen=1;
            }else{
                currLen = min(k, currLen+1);
                if(currLen==k){
                    ans++;
                }
            }
        }
        return ans;
    }
};
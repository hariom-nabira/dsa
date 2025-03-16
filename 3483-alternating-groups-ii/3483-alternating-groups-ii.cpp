class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        for(int i=0; i<k-1; i++){
            colors.push_back(colors[i]);
        }
        int n=colors.size();
        int currLen=1, ans=0;
        for(int i=1; i<n; i++){
            cout<<colors[i]<<" ";
            if(colors[i]==colors[i-1]){
                currLen=1;
            }else{
                currLen = min(k, currLen+1);
                if(currLen==k){
                    ans++;
                }
            }
        }
        // if(currLen==k) ans++;
        return ans;
    }
};
class Solution {
public:
    string generateTag(string caption) {
        int n = caption.size();
        string ans = "#";

        for(int i=0; i<n && ans.size()<100; i++){
            if(caption[i] == ' ')continue;
            if(i>0 && caption[i-1] == ' '){
                caption[i] = toupper(caption[i]);
            }else{
                caption[i] = tolower(caption[i]);
            }
            ans += caption[i]; 
        }
        ans[1] = tolower(ans[1]);
        return ans;
    }
};
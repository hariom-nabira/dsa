class Solution {
public:
    int minMaxDifference(int num) {
        string val, val2;
        val = val2 = to_string(num);
        int n=val.size();
        int i=0;
        while(i<n && val[i]=='9') i++;
        if(i!=n){
            char toChange = val[i];
            for(; i<n; i++){
                if(val[i]==toChange){
                    val[i] = '9';
                }
            }
        }
        int mx = stoi(val);
        i=0;
        while(i<n && val2[i]=='0') i++;
        if(i!=n){
            char toChange = val2[i];
            for(; i<n; i++){
                if(val2[i]==toChange){
                    val2[i]='0';
                }
            }
        }
        int mn = stoi(val2);
        return mx-mn;
    }
};
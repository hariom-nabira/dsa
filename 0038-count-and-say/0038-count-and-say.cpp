class Solution {
public:
    string countAndSay(int n) {
        string str = "1";
        for(int i=0; i<n-1; i++){
            string temp = "";
            int segStartIndex = 0, sz = str.size();
            for(int j=1; j<sz; j++){
                if(str[j]!=str[j-1]){
                    temp += to_string(j - segStartIndex);
                    temp += str[j-1];
                    segStartIndex = j;
                }
            }
            temp += to_string(sz - segStartIndex);
            temp += str[sz-1];
            str = temp;
        }
        return str;
    }
};
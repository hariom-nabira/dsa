class Solution {
private:
    string lastSubstring(string s) {
        int n=s.size(), i=0, j=1, k=0;
        while(j+k < n){
            if(s[i+k]==s[j+k]){
                k++;
                continue;
            }else if(s[i+k] > s[j+k]){
                j = j+k+1;
            }else{
                i = max(i+k+1,j);
                j = i+1;
            }
            k=0;
        }
        return s.substr(i);
    }
public:
    string answerString(string word, int numFriends) {
        if(numFriends==1) return word;
        int n = word.size();
        string ans = lastSubstring(word);
        return ans.substr(0,n-numFriends+1);
    }
};
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        if(y<x){
            reverse(s.begin(), s.end());
            swap(x,y);
        }
        int score = 0;
        stack<char> st;
        for(auto ch:s){
            if(ch=='a' && !st.empty() && st.top()=='b'){
                score += y;
                st.pop();
            }else{
                st.push(ch);
            }
        }
        string temp="";
        while(!st.empty()){
            temp += st.top();
            st.pop();
        }
        for(auto ch:temp){
            if(ch=='a' && !st.empty() && st.top()=='b'){
                score += x;
                st.pop();
            }else{
                st.push(ch);
            }
        }
        return score;
    }
};
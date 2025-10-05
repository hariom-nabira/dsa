        // TOC for the win here!\U0001f973
        // State-Transition Diagram!!

        // I have used +ve number for states ending with '(' 
        // The magnitude tells the no. of consecutive '('s
        // I have capped the +ve states at +k, essensially these state will be in range [1,k]
        
        // Then for states ending with ')', I have used -ve numbers, in the range [-1,-k], meanings same as above
        // 0 is used as the 'start/failure/S₀' state)
        
        // -k is the final state
        // final state mean we have got our k-balanced, string, therefore we pop it (2k chars)

        // after exhausting the character, whats left in the stack is the resultant string
        // since I only stored int in stack, I needed to be able to infer which char {'(' or ')'}, would have resulted the state on top of the stack
        // This is simple once observed!
        // All <= 0 states are reached by ')' brackets only
        // similarly all >0 by '(' only


class Solution {
public:
    string removeSubstring(string s, int k) {
        stack<int> st;
        st.push(0);
        for(auto &ch: s){
            if(ch=='('){
                if(st.top() <= 0) st.push(1);
                else st.push(min(st.top()+1, k));
            }else{
                if(st.top()>=0 && st.top()<k) st.push(0);
                else if(st.top()==k) st.push(-1);
                else st.push(st.top()-1);

                if(st.top() == -k){
                    for(int i=0; i<2*k; i++) st.pop();
                }
            }
        }
        string ans="";
        while(st.size()>1){
            if(st.top()<=0) ans += ')';
            else ans += '(';
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
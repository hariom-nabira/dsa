class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        stack<int> st;
        for(auto e: nums2){
            while(!st.empty() && st.top()<e){
                mp[st.top()] = e;
                st.pop();
            }
            st.push(e);
        }
        while(!st.empty()){
            mp[st.top()] = -1;
            st.pop();
        }
        vector<int> ans;
        for(auto e:nums1) ans.push_back(mp[e]);
        return ans;
    }
};
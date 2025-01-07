//right to left
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& a) {
        int n = a.size();
        vector<int>v(n,-1);

        stack<int>st;
        for(int i = 2*n - 1; i >= 0; i--)
        {
            // we pop out all elements smaller than current element
            while(!st.empty() && (a[i%n] >= st.top()))
            {
                st.pop();
            }

            // if stack is empty means no greater element is there
            // if not empty we make answer at that index equal to top element
            if(!st.empty())
            {
                v[i%n] = st.top();
            }

            st.push(a[i%n]);
        }

        return v;
    }
};





//left to right

// class Solution {
// public:
//     vector<int> nextGreaterElements(vector<int>& nums) {
//         int n=nums.size();
//         vector<int> nums2(nums.begin(), nums.end());
//         nums2.insert(nums2.end(), nums.begin(), nums.end());
//         stack<pair<int,int>> st;
//         vector<int> ans(n,-1);
//         for(int i=0; i < 2*n; i++){
//             cout<<nums2[i]<<" ";
//             while(!st.empty() && st.top().first < nums2[i]){
//                 if(st.top().second < n){
//                     ans[st.top().second] = nums2[i];
//                 }
//                 st.pop();
//             }
//             st.push({nums2[i],i});
//         }
//         return ans;
//     }
// };
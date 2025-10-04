class Solution {
public:
    int longestSubarray(vector<int>& arr, int x) {
        int mxLen=0, l=0, n=arr.size();
        deque<int> mn,mx;
        for(int r=0; r<n; r++){
            while(!mx.empty() && arr[mx.back()] < arr[r]) mx.pop_back();
            mx.push_back(r);
            while(!mn.empty() && arr[mn.back()] > arr[r]) mn.pop_back();
            mn.push_back(r);
            while(arr[mx.front()] - arr[mn.front()] > x){
                l++;
                while(!mn.empty() && mn.front() < l) mn.pop_front();
                while(!mx.empty() && mx.front() < l) mx.pop_front();
            }
            if(r-l+1 > mxLen){
                mxLen = r-l+1;
            }
        }
        return mxLen;
    }
};
//trial

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
       priority_queue<int,vector<int> ,greater<int>> minHeap(nums.begin(),nums.begin()+k);
       for(int i=k;i<nums.size();i++){
        if(nums[i]>minHeap.top()){
            minHeap.pop();
            minHeap.push(nums[i]);
        }
       }
       return minHeap.top();
    }
};
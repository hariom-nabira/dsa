class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n=nums.size();
        int maj = findMajor(nums);
        // cout<<maj<<"\n";
        vector<int> pre(n+1);
        for(int i=1; i<=n; i++){
            pre[i] = pre[i-1] + (nums[i-1]==maj);
            // cout<<pre[i]<<" ";
        }
        // cout<<"\n\n";
        for(int i=0; i<n-1; i++){
            int l=pre[i+1];
            int r=pre[n]-l;
            // cout<<l<<" "<<(i+1)/2<<" "<<r<<" "<<(n-i-1)/2<<"\n";
            if(l>(i+1)/2 && r>(n-i-1)/2) return i;
        }
        return -1;
    }
private:
    int findMajor(vector<int> &nums){
        int cand = nums[0], cnt=1, n=nums.size();
        for(int i=1; i<n; i++){
            if(!cnt){
                cand = nums[i];
                cnt=1;
            }else if(nums[i]==cand){
                cnt++;
            }else{
                cnt--;
            }
        }
        return cand;
    }
};
class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n=nums.size();
        int maj = findMajor(nums);
        int majCnt=0;
        for(int &e:nums){
            majCnt += (e==maj);
        }
        int l=0;
        for(int i=0; i<n-1; i++){
            l += (nums[i]==maj);
            int r = majCnt - l;
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
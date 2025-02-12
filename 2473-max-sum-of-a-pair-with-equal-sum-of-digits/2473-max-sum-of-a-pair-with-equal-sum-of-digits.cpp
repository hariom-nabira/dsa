class Solution {
public:
    int maximumSum(vector<int>& nums) {
        map<int,int>freq;  // O(n);
        map<int,int>mp; // O(log(max value))
        int res = -1;
        for(int i=0; i<nums.size(); i++)freq[nums[i]]++;
        for(int i=0; i<nums.size(); i++){
            int sum=0;
            int temp=nums[i];
            while(temp>0){
               sum+=temp%10;
               temp/=10;
            }
            if(mp.count(sum))
            {
                res = max(nums[i]+mp[sum], res);
            }
            mp[sum]=max(mp[sum],nums[i]);
        }
        return res;
    }
};
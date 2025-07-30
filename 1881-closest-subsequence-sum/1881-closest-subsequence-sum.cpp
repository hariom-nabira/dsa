class Solution {
private:
    void helper(vector<int> &a, int i, int n, vector<int> &v, int curr){
        if(i==n){
            v.push_back(curr);
            return;
        }
        //pick
        helper(a,i+1,n,v,curr+a[i]);
        //non-pick
        helper(a,i+1,n,v,curr);
    }
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        // since 2n<=40, brute subset generation (2^(2n)) wont work
        // but it could work for 2^20, so can we use subset genration on two halfs, and then combine to get a answer?
        // Hmmmmmm! Yes we CAN!
        // if s1 is list of all the subset sums of first half,and s2 of the second and y=2^n
        // then for every element in s1 we have to find its best pair in s2 [O(y*y),y for s1 and y for s2]
        // but if s2 is sorted then O(y*logy)
        int ans = INT_MAX, n = nums.size();
        vector<int> s1,s2;
        helper(nums,0,n/2,s1,0);
        helper(nums,n/2,n,s2,0);
        sort(s2.begin(), s2.end());
        int sz=s2.size();
        for(auto &e: s1){
            int des = goal-e;
            int i = lower_bound(s2.begin(), s2.end(), des) -  s2.begin();
            if(i<sz){
                ans = min(ans, abs(goal - (e+s2[i])));
            }
            if(i>0) ans = min(ans, abs(goal - (e+s2[i-1])));
        }
        return ans;
    }
};
// Meet in the Middle Algo
class Solution {
private:
    void helper(vector<int> &a, int i, int n, vector<vector<int>> &v, int currSum, int cnt){
        if(i==n){
            v[cnt].push_back(currSum);
            return;
        }
        //pick
        helper(a,i+1,n,v,currSum+a[i],cnt+1);
        //non-pick
        helper(a,i+1,n,v,currSum,cnt);
    }
public:
    int minimumDifference(vector<int>& nums) {
        // since 2n<=30, brute subset generation (2^(2n)) wont work
        // but it could work for 2^15, so can we use subset genration on two halfs, and then combine to get a answer?
        // Hmmmmmm! Yes we CAN!
        // if s1 is list of all the subset sums of first half,and s2 of the second, t1 is the sum of entire first half, and t2 of second, and y=2^n
        
        int n = nums.size()/2;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int target = sum/2;
        vector<vector<int>> s1(n+1, vector<int>()), s2(n+1, vector<int>());
        helper(nums,0,n,s1,0,0);
        helper(nums,n,2*n,s2,0,0);

        for(auto &v: s2) sort(v.begin(),v.end());
        int ans=INT_MAX;
        for(int c=0; c<n; c++){
            for(auto &e: s1[c]){
                int des = target-e;
                int i = lower_bound(s2[n-c].begin(), s2[n-c].end(), des) - s2[n-c].begin();
                int sz = s2[n-c].size();
                if(i<sz) ans = min(ans, abs(2*(e+s2[n-c][i])-sum));
                if(i>0) ans = min(ans, abs(2*(e+s2[n-c][i-1])-sum));
            }
        }
        return ans;
    }
};
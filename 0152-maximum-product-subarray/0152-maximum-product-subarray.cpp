// second time bhi nhi hua
// REVISIT !!
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //much cleaner approach
        //ek-baar left-right jao max lete hue
        //dusri baar right-left aao max lete hue
        //0 mila to bas vo carry na ho isliye curr=1 explicitly karo
        int ans = INT_MIN, n=nums.size();
        int curr=1;
        for(int i=0; i<n; i++){
            curr *= nums[i];
            ans = max(ans, curr);
            if(curr==0) curr=1;
        }
        curr=1;
        for(int i=n-1; i>=0; i--){
            curr *= nums[i];
            ans = max(ans, curr);
            if(curr==0) curr=1;
        }
        return ans;
    }
};
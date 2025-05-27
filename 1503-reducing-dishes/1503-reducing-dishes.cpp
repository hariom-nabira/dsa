class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        for(auto &e: satisfaction) cout<<e<<" ";
        int n=satisfaction.size();
        int end = n-1, ans=0, sum=0;
        while(end >= 0){
            int temp = ans + sum + satisfaction[end];
            if(temp < ans) break;
            sum += satisfaction[end--];
            ans = temp;
        }
        return ans;
    }
};
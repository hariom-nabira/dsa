class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int>candies(n, 0);
        vector<pair<int,int>> a;
        for(int i=0; i<n; i++){
            a.push_back({ratings[i], i});
        }
        sort(a.begin(), a.end());
        for(auto [r,ind]: a){
            int mx=0;
            if(ind-1>=0) mx = max(mx, (ratings[ind]==ratings[ind-1])? 0:candies[ind-1]);
            if(ind+1<n) mx = max(mx, (ratings[ind]==ratings[ind+1])? 0:candies[ind+1]);
            candies[ind] = mx+1;
        }
        return accumulate(candies.begin(), candies.end(), 0);
    }
};
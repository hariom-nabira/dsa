class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int> candies(n, 1);
        vector<pair<int,int>> a;
        for(int i=0; i<n; i++){
            a.push_back({ratings[i], i});
        }
        sort(a.begin(), a.end());
        for(auto [r,ind]: a){
            if(ind-1>=0 && ratings[ind]>ratings[ind-1]) candies[ind] = max(candies[ind], candies[ind-1] + 1);
            if(ind+1<n && ratings[ind]>ratings[ind+1]) candies[ind] = max(candies[ind], candies[ind+1] + 1);
            // candies[ind]++;
        }
        return accumulate(candies.begin(), candies.end(), 0);
    }
};
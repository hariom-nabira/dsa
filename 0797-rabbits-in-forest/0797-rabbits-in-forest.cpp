class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int,int> mp;
        for(auto &e: answers) mp[e]++;
        int ans=0;
        for(auto &p: mp){
            ans += ((p.second)/(p.first+1))*(p.first+1);
            if((p.second)%(p.first+1)) ans += (p.first+1);
        }
        return ans;
    }
};
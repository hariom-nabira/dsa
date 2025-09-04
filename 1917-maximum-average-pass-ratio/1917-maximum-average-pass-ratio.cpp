class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto comp = [](const pair<int,int> &a, const pair<int,int> &b){
            double avgInc1 = (a.first+1.0)/(a.second+1.0) - (a.first*1.0)/a.second;
            double avgInc2 = (b.first+1.0)/(b.second+1.0) - (b.first*1.0)/b.second;
            return avgInc1 < avgInc2;
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)> pq(comp);
        for(auto &v: classes){
            pq.push({v[0],v[1]});
        }
        while(extraStudents--){
            auto p = pq.top();
            pq.pop();
            p.first++;
            p.second++;
            pq.push(p);
        }
        int n = classes.size();
        double sum = 0;
        for(int i=0; i<n; i++){
            sum += (pq.top().first * 1.0)/(pq.top().second);
            pq.pop();
        }
        return sum/n;
    }
};
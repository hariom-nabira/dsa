class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto avgInc = [](int &pass, int &total){
            return (double)(pass+1)/(total+1) - (double)pass/total;
        };
        int n = classes.size();
        priority_queue<pair<double,int>> pq;
        for(int i=0; i<n; i++){
            pq.push({avgInc(classes[i][0],classes[i][1]),i});
        }
        while(extraStudents--){
            auto [gain, i] = pq.top();
            pq.pop();
            classes[i][0]++;
            classes[i][1]++;
            pq.push({avgInc(classes[i][0],classes[i][1]), i});
        }
        double sum = 0;
        for(auto &v: classes){
            sum += (double)v[0]/v[1];
        }
        return sum/n;
    }
};
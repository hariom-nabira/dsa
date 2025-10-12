class ExamTracker {
private:
    vector<long long> times;
    vector<long long> scorePre;
public:
    ExamTracker() {
        scorePre = {0};
    }
    
    void record(int time, int score) {
        times.push_back(time);
        scorePre.push_back(scorePre.back() + score);
    }
    
    long long totalScore(int startTime, int endTime) {
        int i = lower_bound(times.begin(), times.end(), startTime) - times.begin();
        int j = upper_bound(times.begin(), times.end(), endTime) - times.begin();
        long long ans = (i==j)? 0: scorePre[j] - scorePre[i];
        return ans;
    }
};
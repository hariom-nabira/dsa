// class Solution {
// public:
//     int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
//         int n = candies.size(), ans=0;
//         vector<bool> found(n);
//         for(auto &b : initialBoxes) found[b] = true;
//         queue<int> q;
//         for(int i=0; i<n; i++){
//             if(found[i] && status[i]) q.push(i);
//             sort(keys[i].begin(), keys[i].end());
//             sort(containedBoxes[i].begin(), containedBoxes[i].end());
//         }
//         while(!q.empty()){
//             int box = q.front(); q.pop();
//             ans += candies[box];
//             candies[box] = 0;
//             for(int i=0; i<n; i++){
//                 if(!found[i]){
//                     if(lower_bound(containedBoxes[box].begin(), containedBoxes[box].end(), i) != containedBoxes[box].end()){
//                         found[i] = true;
//                     }
//                 }
//                 if(!status[i]){
//                     if(lower_bound(keys[box].begin(), keys[box].end(), i) != keys[box].end()){
//                         status[i] = 1;
//                     }
//                 }
//                 if(found[i] && status[i] && candies[i]) q.push(i);
//             }
//         }
//         return ans;
//     }
// };


//cfs

class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys,
                   vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();
        vector<bool> hasBox(n, false), hasKey(n, false), opened(n, false);
        queue<int> q;
        for (int box : initialBoxes) {
            hasBox[box] = true;
        }

        int totalCandies = 0;
        bool progress = true;

        while (progress) {
            progress = false;
            for (int i = 0; i < n; ++i) {
                if (hasBox[i] && (status[i] || hasKey[i]) && !opened[i]) {
                    opened[i] = true;
                    totalCandies += candies[i];
                    progress = true;

                    for (int key : keys[i]) {
                        hasKey[key] = true;
                    }

                    for (int newBox : containedBoxes[i]) {
                        hasBox[newBox] = true;
                    }
                }
            }
        }

        return totalCandies;
    }
};

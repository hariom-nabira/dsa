//cfs
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        // adjacency lists for each vertex
        vector<vector<int>> graph(n);
        // map to store frequency of each unique adjacency list
        unordered_map<string, int> componentFreq;

        // initialize adjacency lists with self-loops
        for (int vertex = 0; vertex < n; vertex++) {
            graph[vertex].push_back(vertex);
        }

        // build adjacency lists from edges
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        // count frequency of each unique adjacency pattern
        for (int vertex = 0; vertex < n; vertex++) {
            vector<int> neighbors = graph[vertex];
            sort(neighbors.begin(), neighbors.end());

            // convert vector to string for hashing
            string key;
            for (int num : neighbors) {
                key += to_string(num) + ",";
            }
            componentFreq[key]++;
        }

        // count complete components where size equals frequency
        int completeCount = 0;
        for (const auto& entry : componentFreq) {
            // count commas to get original vector size
            int size = count(entry.first.begin(), entry.first.end(), ',');
            if (size == entry.second) {
                completeCount++;
            }
        }

        return completeCount;
    }
};



// class Solution {
// public:
//     vector<int> parent, depth;
//     int countCompleteComponents(int n, vector<vector<int>>& edges) {
//         parent.resize(n);
//         depth.resize(n,1);
//         for(int i=0; i<n; i++) parent[i] = i;
//         for(auto &e:edges){
//             myUnion(e[0], e[1]);
//         }
//         unordered_set<int> s;
//         for(auto &i: parent) s.insert(find(i));
//         return (int)s.size();
//     }
// private:
//     int find(int i){
//         if(parent[i]==i) return i;
//         return parent[i] = find(parent[i]);
//     }
//     void myUnion(int x, int y){
//         int r1 = find(x);
//         int r2 = find(y);
//         if(depth[r1]<depth[r2]) swap(r1,r2);
//         if(depth[r1]==depth[r2]) depth[r1]++;
//         parent[r2] = r1;
//     }
// };
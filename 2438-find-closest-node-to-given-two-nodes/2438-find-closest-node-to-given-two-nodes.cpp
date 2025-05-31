class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<int> dist1(n, -1), dist2(n, -1);
        
        dist1[node1] = 0;
        int lastNode = node1;
        while(edges[lastNode]!=-1 && dist1[edges[lastNode]]==-1){
            dist1[edges[lastNode]] = dist1[lastNode]+1;
            lastNode = edges[lastNode];
        }

        dist2[node2] = 0;        
        lastNode = node2;
        while(edges[lastNode]!=-1 && dist2[edges[lastNode]]==-1){
            dist2[edges[lastNode]] = dist2[lastNode]+1;
            lastNode = edges[lastNode];
        }

        int minDist = INT_MAX, ansInd=-1;
        for(int i=0; i<n; i++){
            if(dist1[i]!=-1 && dist2[i]!=-1){
                if(max(dist1[i], dist2[i]) < minDist){
                    minDist = max(dist1[i], dist2[i]);
                    ansInd = i;
                }
            }
        }
        return ansInd;
    }
};
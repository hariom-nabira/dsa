class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size(), hl=-1, hr=-1, vl=-1, vr=-1;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!grid[i][j]) continue;
                if(hl==-1){
                    hl = i;
                }
                hr = i;
                if(vl==-1){
                    vl = j;
                }
                vl = min(vl, j);
                vr = max(vr, j);
            }
        }
        return (hr-hl+1)*(vr-vl+1);
    }
};
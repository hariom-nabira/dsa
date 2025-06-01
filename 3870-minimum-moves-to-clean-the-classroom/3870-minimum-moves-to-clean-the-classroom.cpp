class Solution {
public:
    int minMoves(vector<string>& g, int energy) {
        int r = g.size(), c = g[0].size(); 
        queue<tuple<int,int,int,int>> q; // {x_coord, y_coord, mask, currEnergy}
        unordered_map<int,int> coordToBit;
        int litCount=0;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(g[i][j]=='L'){
                    coordToBit[i*c + j] = litCount++;
                }else if(g[i][j]=='S'){
                    q.emplace(i,j,0,energy);
                }
            }
        }
        int maxMask = 1 << litCount;        // if 3L were there then maxMask = 1000
        int dir[4][2] = {{0,-1}, {0,1}, {-1,0}, {1,0}}; // L,R,U,D
        vector vis(r+1, vector(c+1, vector( energy+1, vector<bool> (maxMask+1, false)))); // vis[r][c][e][maxMask]
        auto [tx,ty,tmask,te] = q.front();
        vis[tx][ty][te][tmask] = true;
        int steps=0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto [x,y,mask,e] = q.front(); q.pop();
                if(mask == maxMask-1) return steps;     // maxMask-1 = 111 (desired)
                if(!e) continue;
                for(int d=0; d<4; d++){
                    int i=x+dir[d][0], j=y+dir[d][1];
                    if(i<0 || i>=r || j<0 || j>=c || g[i][j]=='X') continue;
                    int newMask = mask;
                    if(g[i][j]=='L'){
                        int bit = coordToBit[i*c + j];
                        newMask |= (1<<bit);
                    }
                    int newE = (g[i][j]=='R')? energy: e-1;
                    if(vis[i][j][newE][newMask]) continue;
                    vis[i][j][newE][newMask] = true;
                    q.emplace(i,j,newMask,newE);
                }
            }
            steps++;
        }
        return -1;
    }
};
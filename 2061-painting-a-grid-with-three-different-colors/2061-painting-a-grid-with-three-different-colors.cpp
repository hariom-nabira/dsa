class Solution {
private:
    const int MOD = 1e9 + 7;
public:
    int colorTheGrid(int n, int m){
        // total number of color combinations a column can have
        int cCombTotal = pow(3,n);
        vector<vector<int>> maskToColor(cCombTotal, vector<int>());
        vector<int> validMasks;
        
        // finding equivalent color comb of each mask and filtering for valid ones
        for(int mask=0; mask<cCombTotal; mask++){
            int m = mask;
            // finding color comb equivalent of mask
            for(int i=0; i<n; i++){
                maskToColor[mask].push_back(m%3);
                m/=3;
            }
            // checking if color comb is valid
            int flag = true;
            for(int i=1; i<n; i++){
                if(maskToColor[mask][i] == maskToColor[mask][i-1]){
                    flag = false;
                    break;
                }
            }
            if(flag) validMasks.push_back(mask);
        }

        vector<vector<int>> validAdj(cCombTotal, vector<int>(cCombTotal, 0));
        // precomputing valid adjacency of masks
        for(auto &m1 : validMasks){
            for(auto &m2 : validMasks){
                int flag=true;
                for(int k=0; k<n; k++){
                    if(maskToColor[m1][k]==maskToColor[m2][k]){
                        flag=false;
                        break;
                    }
                }
                // if the colors at all corresponding positions in two validMasks are unequal, only then it is valid adjacency
                if(flag) validAdj[m1][m2] = 1;
            }
        }
        // we are coloring column by column (entire column at a time, using the masks)
        
        // DP State: curr[j][x] -> number of ways of coloring till column 'j' with last column having color comb with mask 'x'
        // DP Transition: dp[j+1][x] = sum(dp[j][y]) over all validAdj mask pairs{x,y}
        
        // Space Optimization:
        // Since dp[j][..] only depends on dp[j-1][..], we will only store two 1-D arrays, instead of a whole 2-D dp array
        // curr -> dp[j-1][..]
        // next -> dp[j][..]

        // initializing with first column
        vector<int> curr(cCombTotal);
        for(auto &m: validMasks){
            curr[m] = 1; // only 1 way of coloring first column with valid mask m
        }
        // going column by column now
        for(int j=1; j<m; j++){
            vector<int> next(cCombTotal);
            for(auto &m1: validMasks){
                for(auto &m2: validMasks){
                    if(validAdj[m1][m2]){
                        next[m2] = (next[m2] + curr[m1])%MOD;
                    }
                }
            }
            curr = next;
        }
        int ans=0;
        for(auto &e: curr) ans = (ans+e)%MOD;
        return ans;
    }
};
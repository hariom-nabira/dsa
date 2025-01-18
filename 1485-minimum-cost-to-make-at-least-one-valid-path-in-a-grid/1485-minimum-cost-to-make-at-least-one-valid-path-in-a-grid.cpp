//cfs
class Solution {
public:
    // Direction vectors: right, left, down, up (matching grid values 1, 2, 3,
    // 4)
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int minCost(vector<vector<int>>& grid) {
        int numRows = grid.size(), numCols = grid[0].size();

        // Min-heap ordered by cost. Each element is {cost, row, col}
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({0, 0, 0});

        // Track minimum cost to reach each cell
        vector<vector<int>> minCost(numRows, vector<int>(numCols, INT_MAX));
        minCost[0][0] = 0;

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            int cost = curr[0], row = curr[1], col = curr[2];

            // Skip if we've found a better path to this cell
            if (minCost[row][col] != cost) continue;

            // Try all four directions
            for (int dir = 0; dir < 4; dir++) {
                int newRow = row + dirs[dir][0];
                int newCol = col + dirs[dir][1];

                // Check if new position is valid
                if (newRow >= 0 && newRow < numRows && newCol >= 0 &&
                    newCol < numCols) {
                    // Add cost=1 if we need to change direction
                    int newCost = cost + (dir != (grid[row][col] - 1) ? 1 : 0);

                    // Update if we found a better path
                    if (minCost[newRow][newCol] > newCost) {
                        minCost[newRow][newCol] = newCost;
                        pq.push({newCost, newRow, newCol});
                    }
                }
            }
        }

        return minCost[numRows - 1][numCols - 1];
    }
};



// // class Solution {
// // public:
// //     int helper(int i, int j, vector<vector<int>>& grid, vector<vector<int>> &dp, int curr){
// //         int n=grid.size(), m=grid[0].size();
// //         cout<<i<<" "<<j<<" ----> "<<curr<<"\n";
// //         // if(i<0 || i>=n || j<0 || j>=m || grid[i][j]==-1) return INT_MAX;
// //         if(i==n-1 && j==m-1) return curr;
// //         if(dp[i][j]!=-1) return dp[i][j];

// //         int og = grid[i][j];
// //         grid[i][j] = -1;
// //         int right = INT_MAX, left = INT_MAX, up = INT_MAX, down = INT_MAX;
// //         if(j+1<m && grid[i][j+1]!=-1){
// //             right = (og==1)? helper(i, j+1, grid, dp, curr) : helper(i, j+1, grid, dp, curr+1);
// //         }
// //         if(j-1>=0 && grid[i][j-1]!=-1){
// //             left = (og==2)? helper(i, j-1, grid, dp, curr) : helper(i, j-1, grid, dp, curr+1);
// //         }
// //         if(i+1<n && grid[i+1][j]!=-1){
// //             down = (og==3)? helper(i+1, j, grid, dp, curr) : helper(i+1, j, grid, dp, curr+1);
// //         }
// //         if(i-1>=0 && grid[i-1][j]!=-1){
// //             up = (og==4)? helper(i-1, j, grid, dp, curr) : helper(i-1, j, grid, dp, curr+1);
// //         }

// //         int ans = min({right, left, down, up});
        
// //         grid[i][j] = og;
// //         return dp[i][j] = ans;
// //     }
// //     int minCost(vector<vector<int>>& grid) {
// //         int n=grid.size(), m=grid[0].size();
// //         vector<vector<int>> dp(n, vector<int>(m, -1));
// //         return helper(0,0,grid,dp,0);
// //     }
// // };

// class Solution {
// public:
//     int helper(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp, int curr) {
//         int n = grid.size(), m = grid[0].size();

//         // Base Case: Reached bottom-right corner
//         if (i == n - 1 && j == m - 1) return curr;

//         // Memoization: If already computed, return the result
//         if (dp[i][j] != -1) return dp[i][j];

//         int og = grid[i][j]; // Original grid value
//         grid[i][j] = -1; // Mark current cell as visited

//         // Initialize costs for each direction
//         int right = INT_MAX, left = INT_MAX, down = INT_MAX, up = INT_MAX;

//         // Recursive exploration with direction costs
//         if (j + 1 < m && grid[i][j + 1] != -1) {
//             right = (og == 1) ? helper(i, j + 1, grid, dp, curr)
//                               : helper(i, j + 1, grid, dp, curr + 1);
//         }
//         if (j - 1 >= 0 && grid[i][j - 1] != -1) {
//             left = (og == 2) ? helper(i, j - 1, grid, dp, curr)
//                              : helper(i, j - 1, grid, dp, curr + 1);
//         }
//         if (i + 1 < n && grid[i + 1][j] != -1) {
//             down = (og == 3) ? helper(i + 1, j, grid, dp, curr)
//                              : helper(i + 1, j, grid, dp, curr + 1);
//         }
//         if (i - 1 >= 0 && grid[i - 1][j] != -1) {
//             up = (og == 4) ? helper(i - 1, j, grid, dp, curr)
//                            : helper(i - 1, j, grid, dp, curr + 1);
//         }

//         // Calculate the minimum cost from all directions
//         int ans = min({right, left, down, up});

//         grid[i][j] = og; // Restore grid value for other paths

//         // If no valid path exists, return INT_MAX; otherwise, return computed cost
//         return dp[i][j] = (ans == INT_MAX) ? INT_MAX : ans;
//     }

//     int minCost(vector<vector<int>>& grid) {
//         int n = grid.size(), m = grid[0].size();
//         vector<vector<int>> dp(n, vector<int>(m, -1)); // DP table for memoization
//         int result = helper(0, 0, grid, dp, 0);

//         // If result is INT_MAX, there's no valid path
//         return result == INT_MAX ? -1 : result;
//     }
// };

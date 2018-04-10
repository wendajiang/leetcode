/*
 * [64] Minimum Path Sum
 *
 * https://leetcode.com/problems/minimum-path-sum/description/
 *
 * algorithms
 * Medium (40.44%)
 * Total Accepted:    146.4K
 * Total Submissions: 359.2K
 * Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
 *
 * Given a m x n grid filled with non-negative numbers, find a path from top
 * left to bottom right which minimizes the sum of all numbers along its path.
 *
 * Note: You can only move either down or right at any point in time.
 *
 * Example 1:
 *
 * [[1,3,1],
 * ⁠[1,5,1],
 * ⁠[4,2,1]]
 *
 * Given the above grid map, return 7. Because the path 1→3→1→1→1 minimizes the
 * sum.
 *
 */
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if(m == 0) return 0;
        int n = grid[0].size();
        int dp[m][n];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = grid[0][0];
        for(int i = 0 ; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i > 0 && j > 0){
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
                }else if(i > 0 && j == 0){
                    dp[i][j] = dp[i - 1][j] + grid[i][j];
                }else if(i == 0 && j > 0){
                    dp[i][j] = dp[i][j - 1] + grid[i][j];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};

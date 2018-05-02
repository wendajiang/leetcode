/*
 * [221] Maximal Square
 *
 * https://leetcode.com/problems/maximal-square/description/
 *
 * algorithms
 * Medium (30.42%)
 * Total Accepted:    87.7K
 * Total Submissions: 288.1K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 *
 * Given a 2D binary matrix filled with 0's and 1's, find the largest square
 * containing only 1's and return its area.
 *
 *
 * For example, given the following matrix:
 *
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1
 * 1 0 0 1 0
 *
 * Return 4.
 *
 *
 * Credits:Special thanks to @Freezen for adding this problem and creating all
 * test cases.
 */
class Solution {
public:

    //dp[i][j] 表示i, j右下角的正方形的最大边长
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        int M = matrix.size(), N = matrix[0].size();
        int res = 0;
        vector<vector<int>> dp(M, vector<int>(N, 0));
        for(int i = 0; i < M; i++){
            if(matrix[i][0] == '1'){
                dp[i][0] = 1;
                res = 1;
            }
        }
        for(int j = 0; j < N; j++){
            if(matrix[0][j] == '1'){
                dp[0][j] = 1;
                res = 1;
            }
        }
        for(int i = 1; i < M; i++){
            for(int j = 1; j < N; j++){
                if(matrix[i][j] == '1')
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                res  = max(res, dp[i][j]);
            }
        }
        return res * res;
    }
};

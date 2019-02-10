/*
 * [120] Triangle
 *
 * https://leetcode.com/problems/triangle/description/
 *
 * algorithms
 * Medium (34.93%)
 * Total Accepted:    132.5K
 * Total Submissions: 378.1K
 * Testcase Example:  '[[2],[3,4],[6,5,7],[4,1,8,3]]'
 *
 * Given a triangle, find the minimum path sum from top to bottom. Each step
 * you may move to adjacent numbers on the row below.
 *
 * For example, given the following triangle
 *
 *
 * [
 * ⁠    [2],
 * ⁠   [3,4],
 * ⁠  [6,5,7],
 * ⁠ [4,1,8,3]
 * ]
 *
 *
 * The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 *
 * Note:
 *
 * Bonus point if you are able to do this using only O(n) extra space, where n
 * is the total number of rows in the triangle.
 *
 */
class Solution {
public:
    // int minimumTotal(vector<vector<int>>& triangle) {
    //     int len = triangle.size();
    //     if(len == 0) return 0;
    //     vector<vector<int>> dp(len, vector<int>(len, 0));
    //     dp[0][0] = triangle[0][0];
    //     for(int i = 1; i < len; i++){
    //         dp[i][0] = dp[i - 1][0] + triangle[i][0];
    //         dp[i][triangle[i].size() - 1] = dp[i - 1][triangle[i - 1].size() - 1] + triangle[i][triangle[i].size() - 1];
    //         for(int j = 1; j < triangle[i].size() - 1; j++){
    //             dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];
    //         }
    //     }
    //     int res = INT_MAX;
    //     for(int i = 0; i < len; i++){
    //         res = min(res, dp[len - 1][i]);
    //     }
    //     return res;
    // }

    int minimumTotal(vector<vector<int>>& triangle) {
        int len = triangle.size();
        if(len == 0) return 0;
        vector<vector<int>> dp(2, vector<int>(len, 0));
        bool flag = false;
        dp[0][0] = triangle[0][0];
        for(int i = 1; i < len; i++){
            flag = !flag;
            dp[flag][0] = dp[!flag][0] + triangle[i][0];
            dp[flag][triangle[i].size() - 1] = dp[!flag][triangle[i - 1].size() - 1] + triangle[i][triangle[i].size() - 1];
            for(int j = 1; j < triangle[i].size() - 1; j++){
                dp[flag][j] = min(dp[!flag][j], dp[!flag][j - 1]) + triangle[i][j];
            }
        }
        int res = INT_MAX;
        for(int i = 0; i < len; i++){
            res = min(res, dp[flag][i]);
        }
        return res;
    }
};

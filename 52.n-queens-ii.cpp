/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 *
 * https://leetcode.com/problems/n-queens-ii/description/
 *
 * algorithms
 * Hard (63.66%)
 * Likes:    1191
 * Dislikes: 196
 * Total Accepted:    187.8K
 * Total Submissions: 295.1K
 * Testcase Example:  '4'
 *
 * The n-queens puzzle is the problem of placing n queens on an n x n
 * chessboard such that no two queens attack each other.
 *
 * Given an integer n, return the number of distinct solutions to the n-queens
 * puzzle.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 4
 * Output: 2
 * Explanation: There are two distinct solutions to the 4-queens puzzle as
 * shown.
 *
 *
 * Example 2:
 *
 *
 * Input: n = 1
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 9
 *
 *
 */

// @lc code=start
class Solution {
public:
    int totalNQueens(int n) {
        cols = vector<bool>(n, 0);
        diag1 = vector<bool>(2 * n - 1, 0);
        diag2 = vector<bool>(2 * n - 1, 0);

        ans = 0;
        nqueens(0, n);

        return ans;
    }

private:
    vector<bool> cols;
    vector<bool> diag1;
    vector<bool> diag2;
    int ans;

    bool available(int x, int y, int n) {
        return !cols[x] && !diag1[x + y] && !diag2[x - y + n - 1];
    }

    void updateBoard(int x, int y, int n, bool is_put) {
        cols[x] = is_put;
        diag1[x + y] = is_put;
        diag2[x - y + n - 1] = is_put;
    }


    void nqueens(int y, int n) {
        if (y == n) {
            ans += 1;
            return;
        }

        for (int x = 0; x < n; x++) {
            if (!available(x, y, n)) continue;
            updateBoard(x, y, n, true);
            nqueens(y + 1, n);
            updateBoard(x, y, n, false);
        }
    }
};
// @lc code=end

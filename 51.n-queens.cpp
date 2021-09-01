/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 *
 * https://leetcode.com/problems/n-queens/description/
 *
 * algorithms
 * Hard (49.04%)
 * Likes:    4004
 * Dislikes: 123
 * Total Accepted:    296.9K
 * Total Submissions: 552.6K
 * Testcase Example:  '4'
 *
 * The n-queens puzzle is the problem of placing n queens on an n x n
 * chessboard such that no two queens attack each other.
 *
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 * You may return the answer in any order.
 *
 * Each solution contains a distinct board configuration of the n-queens'
 * placement, where 'Q' and '.' both indicate a queen and an empty space,
 * respectively.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 4
 * Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
 * Explanation: There exist two distinct solutions to the 4-queens puzzle as
 * shown above
 *
 *
 * Example 2:
 *
 *
 * Input: n = 1
 * Output: [["Q"]]
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
    vector<vector<string>> solveNQueens(int n) {
        solu.clear();
        board = vector<string>(n, string(n, '.'));
        cols = vector<int>(n, 0);
        diag1 = vector<int>(2 * n - 1, 0);
        diag2 = vector<int>(2 * n - 1, 0);

        nqueens(n, 0);
        return solu;
    }
private:
    vector<string> board;
    vector<int> cols;
    vector<int> diag1;
    vector<int> diag2;
    vector<vector<string>> solu;

    bool available(int x, int y, int n) {
        return !cols[x] && !diag1[x + y] && !diag2[x - y + n - 1];
    }

    void updateBoard(int x, int y, int n, bool is_put) {
        cols[x] = is_put;
        diag1[x + y] = is_put;
        diag2[x - y + n - 1] = is_put;
        board[y][x] = is_put ? 'Q' : '.';
    }

    void nqueens(const int n, const int y) {
        if (y == n) {
            solu.push_back(board);
            return;
        }
        for (int x = 0; x < n; ++x) {
            if (!available(x, y, n)) continue;
            updateBoard(x, y, n, true);
            nqueens(n, y + 1);
            updateBoard(x, y, n, false);
        }
    }
};
// @lc code=end

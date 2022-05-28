/*
 * @lc app=leetcode id=52 lang=rust
 *
 * [52] N-Queens II
 *
 * https://leetcode.com/problems/n-queens-ii/description/
 *
 * algorithms
 * Hard (64.37%)
 * Likes:    1764
 * Dislikes: 211
 * Total Accepted:    221.6K
 * Total Submissions: 333.3K
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
impl Solution {
    pub fn total_n_queens(n: i32) -> i32 {
        let n = n as usize;
        let mut cols: Vec<bool> = vec![false; n];
        let mut diag: Vec<bool> = vec![false; n * 2];
        let mut anti_diag: Vec<bool> = vec![false; n * 2];
        let mut res = 0;
        Self::helper(n, 0, &mut cols, &mut diag, &mut anti_diag, &mut res);
        res
    }
    fn helper(
        n: usize,
        row: usize,
        cols: &mut Vec<bool>,
        diag: &mut Vec<bool>,
        anti_diag: &mut Vec<bool>,
        res: &mut i32,
    ) {
        if row == n {
            *res += 1;
        }

        for col in (0..n) {
            let idx1 = col - row + n;
            let idx2 = col + row;
            if cols[col] || diag[idx1] || anti_diag[idx2] {
                continue;
            }
            cols[col] = true;
            diag[idx1] = true;
            anti_diag[idx2] = true;
            Self::helper(n, row + 1, cols, diag, anti_diag, res);
            cols[col] = false;
            diag[idx1] = false;
            anti_diag[idx2] = false;
        }
    }
}
// @lc code=end

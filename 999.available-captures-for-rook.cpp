/*
 * @lc app=leetcode id=999 lang=cpp
 *
 * [999] Available Captures for Rook
 *
 * https://leetcode.com/problems/available-captures-for-rook/description/
 *
 * algorithms
 * Easy (66.78%)
 * Likes:    359
 * Dislikes: 525
 * Total Accepted:    44.2K
 * Total Submissions: 65.4K
 * Testcase Example:  '[[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".","R",".",".",".","p"],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."]]'
 *
 * On an 8 x 8 chessboard, there is exactly one white rook 'R' and some number
 * of white bishops 'B', black pawns 'p', and empty squares '.'.
 *
 * When the rook moves, it chooses one of four cardinal directions (north,
 * east, south, or west), then moves in that direction until it chooses to
 * stop, reaches the edge of the board, captures a black pawn, or is blocked by
 * a white bishop. A rook is considered attacking a pawn if the rook can
 * capture the pawn on the rook's turn. The number of available captures for
 * the white rook is the number of pawns that the rook is attacking.
 *
 * Return the number of available captures for the white rook.
 *
 *
 * Example 1:
 *
 *
 * Input: board =
 * [[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".","R",".",".",".","p"],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."]]
 * Output: 3
 * Explanation: In this example, the rook is attacking all the pawns.
 *
 *
 * Example 2:
 *
 *
 * Input: board =
 * [[".",".",".",".",".",".",".","."],[".","p","p","p","p","p",".","."],[".","p","p","B","p","p",".","."],[".","p","B","R","B","p",".","."],[".","p","p","B","p","p",".","."],[".","p","p","p","p","p",".","."],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."]]
 * Output: 0
 * Explanation: The bishops are blocking the rook from attacking any of the
 * pawns.
 *
 *
 * Example 3:
 *
 *
 * Input: board =
 * [[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".","p",".",".",".","."],["p","p",".","R",".","p","B","."],[".",".",".",".",".",".",".","."],[".",".",".","B",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".",".",".",".",".","."]]
 * Output: 3
 * Explanation: The rook is attacking the pawns at positions b5, d6, and
 * f5.
 *
 *
 *
 * Constraints:
 *
 *
 * board.length == 8
 * board[i].length == 8
 * board[i][j] is either 'R', '.', 'B', or 'p'
 * There is exactly one cell with board[i][j] == 'R'
 *
 *
 */

// @lc code=start
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int ans = 0;
        auto check = [&](int x, int y, int dx, int dy) {
            x += dx;
            y += dy;
            while(x >= 0 && x < 8 && y >= 0 && y < 8) {
                if (board[x][y] == 'p') return 1;
                if (board[x][y] != '.') break;
                x += dx;
                y += dy;
            }
            return 0;
        };
        array<int, 5> dirs{1, 0, -1, 0, 1};
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] == 'R') {
                    for (int k = 0; k < 4; k++) {
                        ans += check(i, j, dirs[k], dirs[k + 1]);
                    }
                }
            }
        }
        return ans;

    }
};
// @lc code=end

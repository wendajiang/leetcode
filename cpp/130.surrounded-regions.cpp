/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 *
 * https://leetcode.com/problems/surrounded-regions/description/
 *
 * algorithms
 * Medium (24.80%)
 * Likes:    1194
 * Dislikes: 546
 * Total Accepted:    187.8K
 * Total Submissions: 737.5K
 * Testcase Example:  '[["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]'
 *
 * Given a 2D board containing 'X' and 'O' (the letter O), capture all regions
 * surrounded by 'X'.
 * 
 * A region is captured by flipping all 'O's into 'X's in that surrounded
 * region.
 * 
 * Example:
 * 
 * 
 * X X X X
 * X O O X
 * X X O X
 * X O X X
 * 
 * 
 * After running your function, the board should be:
 * 
 * 
 * X X X X
 * X X X X
 * X X X X
 * X O X X
 * 
 * 
 * Explanation:
 * 
 * Surrounded regions shouldn’t be on the border, which means that any 'O' on
 * the border of the board are not flipped to 'X'. Any 'O' that is not on the
 * border and it is not connected to an 'O' on the border will be flipped to
 * 'X'. Two cells are connected if they are adjacent cells connected
 * horizontally or vertically.
 * 
 */

// @lc code=start
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int M = board.size();
        if (M == 0) return;
        int N = board[0].size();
        if (M <= 2 || N <= 2) return;

        for (int i = 0; i < M; i++) {
            if (board[i][0] == 'O')
                mark(board, i, 0, M, N);
            if (board[i][N - 1] == 'O')
                mark(board, i, N - 1, M, N);
        }

        for (int j = 0; j < N; j++) {
            if (board[0][j] == 'O')
                mark(board, 0, j, M, N);
            if (board[M - 1][j] == 'O')
                mark(board, M - 1, j, M, N);
        }

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == '$') board[i][j] = 'O';
                else if (board[i][j] == 'O') board[i][j] = 'X';
            }
        }
        return;
    }
    bool isSafe(int row, int col, int M, int N) {
        return (row >= 0) && (row < M) && (col >= 0) && (col < N);
    }
    void mark(vector<vector<char>>& board, int row, int col, int M, int N) {
        vector<pair<int, int>> adj{{-1, 0},{0, -1},{1, 0},{0, 1}}; 
        board[row][col] = '$';
        for (auto pp : adj) {
            int nr = row + pp.first;
            int nc = col + pp.second;
            if (isSafe(nr, nc, M, N) && board[nr][nc] == 'O')
                mark(board, nr, nc, M, N);
        }
    }
};
// @lc code=end

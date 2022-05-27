/*
 * @lc app=leetcode id=773 lang=cpp
 *
 * [773] Sliding Puzzle
 *
 * https://leetcode.com/problems/sliding-puzzle/description/
 *
 * algorithms
 * Hard (62.14%)
 * Likes:    1195
 * Dislikes: 32
 * Total Accepted:    61.4K
 * Total Submissions: 98.5K
 * Testcase Example:  '[[1,2,3],[4,0,5]]'
 *
 * On an 2 x 3 board, there are five tiles labeled from 1 to 5, and an empty
 * square represented by 0. A move consists of choosing 0 and a 4-directionally
 * adjacent number and swapping it.
 *
 * The state of the board is solved if and only if the board is
 * [[1,2,3],[4,5,0]].
 *
 * Given the puzzle board board, return the least number of moves required so
 * that the state of the board is solved. If it is impossible for the state of
 * the board to be solved, return -1.
 *
 *
 * Example 1:
 *
 *
 * Input: board = [[1,2,3],[4,0,5]]
 * Output: 1
 * Explanation: Swap the 0 and the 5 in one move.
 *
 *
 * Example 2:
 *
 *
 * Input: board = [[1,2,3],[5,4,0]]
 * Output: -1
 * Explanation: No number of moves will make the board solved.
 *
 *
 * Example 3:
 *
 *
 * Input: board = [[4,1,2],[5,0,3]]
 * Output: 5
 * Explanation: 5 is the smallest number of moves that solves the board.
 * An example path:
 * After move 0: [[4,1,2],[5,0,3]]
 * After move 1: [[4,1,2],[0,5,3]]
 * After move 2: [[0,1,2],[4,5,3]]
 * After move 3: [[1,0,2],[4,5,3]]
 * After move 4: [[1,2,0],[4,5,3]]
 * After move 5: [[1,2,3],[4,5,0]]
 *
 *
 * Example 4:
 *
 *
 * Input: board = [[3,2,4],[1,5,0]]
 * Output: 14
 *
 *
 *
 * Constraints:
 *
 *
 * board.length == 2
 * board[i].length == 3
 * 0 <= board[i][j] <= 5
 * Each value board[i][j] is unique.
 *
 *
 */

// @lc code=start
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        int res = 0;
        set<vector<vector<int>>> visited;
        queue<pair<vector<vector<int>>, vector<int>>> q;
        vector<vector<int>> correct{{1,2,3}, {4,5,0}};
        vector<vector<int>> dirs{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == 0) q.push({board, {i, j}});
            }
        }

        while(!q.empty()) {
            for (int i = q.size() - 1; i >= 0; i--) {
                auto t = q.front().first;
                auto zero = q.front().second; q.pop();
                if (t == correct) return res;
                visited.insert(t);
                for (auto dir : dirs) {
                    int x = zero[0] + dir[0], y = zero[1] + dir[1];
                    if (x < 0 || x >=2 || y < 0 || y >= 3) continue;
                    vector<vector<int>> cand = t;
                    swap(cand[zero[0]][zero[1]], cand[x][y]);
                    if (visited.count(cand)) continue;
                    q.push({cand, {x, y}});
                }
            }
            ++res;
        }

        return -1;
    }
};
// @lc code=end

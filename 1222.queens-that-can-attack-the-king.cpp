/*
 * @lc app=leetcode id=1222 lang=cpp
 *
 * [1222] Queens That Can Attack the King
 *
 * https://leetcode.com/problems/queens-that-can-attack-the-king/description/
 *
 * algorithms
 * Medium (70.17%)
 * Likes:    558
 * Dislikes: 103
 * Total Accepted:    27.8K
 * Total Submissions: 39.6K
 * Testcase Example:  '[[0,1],[1,0],[4,0],[0,4],[3,3],[2,4]]\n[0,0]'
 *
 * On an 8x8 chessboard, there can be multiple Black Queens and one White
 * King.
 *
 * Given an array of integer coordinates queens that represents the positions
 * of the Black Queens, and a pair of coordinates king that represent the
 * position of the White King, return the coordinates of all the queens (in any
 * order) that can attack the King.
 *
 * Example 1:
 *
 *
 *
 *
 * Input: queens = [[0,1],[1,0],[4,0],[0,4],[3,3],[2,4]], king = [0,0]
 * Output: [[0,1],[1,0],[3,3]]
 * Explanation: 
 * The queen at [0,1] can attack the king cause they're in the same row.
 * The queen at [1,0] can attack the king cause they're in the same column.
 * The queen at [3,3] can attack the king cause they're in the same diagnal.
 * The queen at [0,4] can't attack the king cause it's blocked by the queen at
 * [0,1].
 * The queen at [4,0] can't attack the king cause it's blocked by the queen at
 * [1,0].
 * The queen at [2,4] can't attack the king cause it's not in the same
 * row/column/diagnal as the king.
 *
 *
 * Example 2:
 *
 *
 *
 *
 * Input: queens = [[0,0],[1,1],[2,2],[3,4],[3,5],[4,4],[4,5]], king = [3,3]
 * Output: [[2,2],[3,4],[4,4]]
 *
 *
 * Example 3:
 *
 *
 *
 *m
 * Input: queens =
 * [[5,6],[7,7],[2,1],[0,7],[1,6],[5,1],[3,7],[0,3],[4,0],[1,2],[6,3],[5,0],[0,4],[2,2],[1,1],[6,4],[5,4],[0,0],[2,6],[4,5],[5,2],[1,4],[7,5],[2,3],[0,5],[4,2],[1,0],[2,7],[0,1],[4,6],[6,1],[0,6],[4,3],[1,7]],
 * king = [3,4]
 * Output: [[2,3],[1,4],[1,6],[3,7],[4,3],[5,4],[4,5]]
 *
 *
 * Constraints:
 *
 *
 * 1 <= queens.length <= 63
 * queens[i].length == 2
 * 0 <= queens[i][j] < 8
 * king.length == 2
 * 0 <= king[0], king[1] < 8
 * At most one piece is allowed in a cell.
 *
 *
 */

// @lc code=start
class Solution {
public:
  vector<vector<int>> queensAttacktheKing(vector<vector<int>> &queens,
                                          vector<int> &king) {
    vector<vector<int>> b(8, vector<int>(8));
    for (const auto &q : queens)
      b[q[0]][q[1]] = 1;
    vector<vector<int>> ans;
    for (const auto &q : queens) {
      for (int dx = -1; dx <= 1; ++dx)
        for (int dy = -1; dy <= 1; ++dy) {
          if (dx == 0 && dy == 0)
            continue;
          int x = q[1] + dx;
          int y = q[0] + dy;
          while (x >= 0 && y >= 0 && x < 8 && y < 8 && !b[y][x]) {
            if (x == king[1] && y == king[0])
              ans.push_back(q);
            x += dx;
            y += dy;
          }
        }
    }
    return ans;
  }
  // vector<vector<int>> queensAttacktheKing(vector<vector<int>> &queens,
                                          // vector<int> &king) {
    // vector<vector<int>> ans;
    // tag = vector<vector<int>>(8, vector<int>{});
    // for (auto &vec : queens) {
      // attach(vec[0], vec[1], king[0], king[1]);
    // }
    // for (auto &v : tag) {
      // if (!v.empty())
        // ans.push_back(v);
    // }
    // return ans;
  // }

private:
  vector<vector<int>> tag;

  int getTagIndex(int x, int y, int i, int j) {
    if (x == i && y < j)
      return 0;
    if (x == i && y > j)
      return 1;
    if (y == j && x < i)
      return 2;
    if (y == j && x > i)
      return 3;
    if (x + y == i + j && x < i)
      return 4;
    if (x + y == i + j && x > i)
      return 5;
    if (x - y + 7 == i - j + 7 && x < i)
      return 6;
    if (x - y + 7 == i - j + 7 && x > i)
      return 7;
    return -1;
  }

  int distance(vector<int> a, vector<int> b) {
    return pow(a[0] - b[0], 2) + pow(a[1] - b[1], 2);
  }

  void attach(int x, int y, int i, int j) {
    if ((x == i) || (y == j) || (x + y == i + j) || (x - y + 7 == i - j + 7)) {
      int k = getTagIndex(x, y, i, j);
      if (tag[k].empty()) {
        tag[k] = vector<int>{x, y};
      } else {
        vector<int> a{x, y};
        vector<int> b = tag[k];
        int d_a = distance(a, vector<int>{i, j});
        int d_b = distance(b, vector<int>{i, j});
        if (d_a > d_b)
          tag[k] = b;
        else
          tag[k] = a;
      }
    }
  }
};
// @lc code=end

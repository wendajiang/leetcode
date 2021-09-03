/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 *
 * https://leetcode.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (51.22%)
 * Likes:    9937
 * Dislikes: 269
 * Total Accepted:    1.2M
 * Total Submissions: 2.3M
 * Testcase Example:
 * '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * Given an m x n 2D binary grid grid which represents a map of '1's (land) and
 * '0's (water), return the number of islands.
 *
 * An island is surrounded by water and is formed by connecting adjacent lands
 * horizontally or vertically. You may assume all four edges of the grid are
 * all surrounded by water.
 *
 *
 * Example 1:
 *
 *
 * Input: grid = [
 * ⁠ ["1","1","1","1","0"],
 * ⁠ ["1","1","0","1","0"],
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["0","0","0","0","0"]
 * ]
 * Output: 1
 *
 *
 * Example 2:
 *
 *
 * Input: grid = [
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["0","0","1","0","0"],
 * ⁠ ["0","0","0","1","1"]
 * ]
 * Output: 3
 *
 *
 *
 * Constraints:
 *
 *
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 300
 * grid[i][j] is '0' or '1'.
 *
 *
 */

// @lc code=start
class UnionSet {
public:
    UnionSet() {}

    void init(int size) {
        rank = vector<int>(size, 1);
        fa = vector<int>(size, 0);
        for (int i = 0; i < size; i++) {
            fa[i] = i;
        }
    }
    int find(int x) {
        if (x != fa[x]) fa[x] = find(fa[x]);
        return fa[x];
    }

    void unionSet(int x, int y) {
        int xx = find(x);
        int yy = find(y);
        if (xx == yy) return;
        if (rank[xx] > rank[yy]) swap(xx, yy);
        fa[xx] = yy;
        rank[yy] += rank[xx];
    }

    void setVal(int index, int val) {
        fa[index] = val;
    }

    int getVal(int index) {
        return fa[index];
    }

private:
    vector<int> fa;
    vector<int> rank;
};
class Solution {
public:
    // int numIslands(vector<vector<char>>& grid) {
    // if (grid.empty()) return 0;
    // int m = grid.size();
    // int n = grid[0].size();
    // int ans = 0;
    // for (int i = 0; i < m; i++) {
    // for (int j = 0; j < n; j++) {
    // if (grid[i][j] == '0') continue;
    // if (grid[i][j] == '1') {
    // ans++;
    // grid[i][j] += 1;
    // dfs(grid, i, j, m, n);
    // }
    // }
    // }
    // return ans;
    // }

    int numIslands(vector<vector<char>> &grid) {
        if (grid.empty()) return 0;
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        s.init(m * n);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1')
                    for (int k = 0; k < 4; k++) {
                        int n_i = i + dx[k];
                        int n_j = j + dy[k];
                        if (n_i >= 0 && n_i < m && n_j >= 0 && n_j < n &&
                            grid[n_i][n_j] == '1') {
                            s.unionSet(n * i + j, n * n_i + n_j);
                        }
                    }
            }
        }
        unordered_set<int> tmp;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') tmp.insert(s.find(n * i + j));
            }
        }

        return tmp.size();
    }

private:
    const vector<int> dx{-1, 1, 0, 0};
    const vector<int> dy{0, 0, 1, -1};
    UnionSet s;
    void dfs(vector<vector<char>> &grid, int i, int j, int m, int n) {
        for (int k = 0; k < 4; k++) {
            int n_i = i + dx[k];
            int n_j = j + dy[k];
            if (n_i >= 0 && n_i < m && n_j >= 0 && n_j < n &&
                grid[n_i][n_j] == '1') {
                grid[n_i][n_j] += 1;
                dfs(grid, n_i, n_j, m, n);
            }
        }
    }
};
// @lc code=end

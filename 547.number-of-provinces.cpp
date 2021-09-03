/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Number of Provinces
 *
 * https://leetcode.com/problems/number-of-provinces/description/
 *
 * algorithms
 * Medium (61.85%)
 * Likes:    3691
 * Dislikes: 203
 * Total Accepted:    319.3K
 * Total Submissions: 516.2K
 * Testcase Example:  '[[1,1,0],[1,1,0],[0,0,1]]'
 *
 * There are n cities. Some of them are connected, while some are not. If city
 * a is connected directly with city b, and city b is connected directly with
 * city c, then city a is connected indirectly with city c.
 *
 * A province is a group of directly or indirectly connected cities and no
 * other cities outside of the group.
 *
 * You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the
 * i^th city and the j^th city are directly connected, and isConnected[i][j] =
 * 0 otherwise.
 *
 * Return the total number of provinces.
 *
 *
 * Example 1:
 *
 *
 * Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
 * Output: 3
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 200
 * n == isConnected.length
 * n == isConnected[i].length
 * isConnected[i][j] is 1 or 0.
 * isConnected[i][i] == 1
 * isConnected[i][j] == isConnected[j][i]
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

    void uion(int x, int y) {
        int xx = find(x);
        int yy = find(y);
        if (xx == yy) return;
        if (rank[xx] > rank[yy]) swap(xx, yy);
        fa[xx] = yy;
        rank[yy] += rank[xx];
    }

private:
    vector<int> fa;
    vector<int> rank;
};
class Solution {
public:
    int findCircleNum(vector<vector<int>> &isConnected) {
        s.init(isConnected.size());

        for (int i = 0; i < isConnected.size(); i++) {
            for (int j = 0; j < isConnected[i].size(); j++) {
                if (isConnected[i][j]) s.uion(i, j);
            }
        }

        unordered_set<int> tmp;
        for (int i = 0; i < isConnected.size(); i++) {
            tmp.insert(s.find(i));
        }

        return tmp.size();
    }

private:
    UnionSet s;
};
// @lc code=end

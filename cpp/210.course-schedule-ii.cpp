/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 *
 * https://leetcode.com/problems/course-schedule-ii/description/
 *
 * algorithms
 * Medium (44.95%)
 * Likes:    6730
 * Dislikes: 237
 * Total Accepted:    630.1K
 * Total Submissions: 1.3M
 * Testcase Example:  '2\n[[1,0]]'
 *
 * There are a total of numCourses courses you have to take, labeled from 0 to
 * numCourses - 1. You are given an array prerequisites where prerequisites[i]
 * = [ai, bi] indicates that you must take course bi first if you want to take
 * course ai.
 *
 *
 * For example, the pair [0, 1], indicates that to take course 0 you have to
 * first take course 1.
 *
 *
 * Return the ordering of courses you should take to finish all courses. If
 * there are many valid answers, return any of them. If it is impossible to
 * finish all courses, return an empty array.
 *
 *
 * Example 1:
 *
 *
 * Input: numCourses = 2, prerequisites = [[1,0]]
 * Output: [0,1]
 * Explanation: There are a total of 2 courses to take. To take course 1 you
 * should have finished course 0. So the correct course order is [0,1].
 *
 *
 * Example 2:
 *
 *
 * Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
 * Output: [0,2,1,3]
 * Explanation: There are a total of 4 courses to take. To take course 3 you
 * should have finished both courses 1 and 2. Both courses 1 and 2 should be
 * taken after you finished course 0.
 * So one correct course order is [0,1,2,3]. Another correct ordering is
 * [0,2,1,3].
 *
 *
 * Example 3:
 *
 *
 * Input: numCourses = 1, prerequisites = []
 * Output: [0]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= numCourses <= 2000
 * 0 <= prerequisites.length <= numCourses * (numCourses - 1)
 * prerequisites[i].length == 2
 * 0 <= ai, bi < numCourses
 * ai != bi
 * All the pairs [ai, bi] are distinct.
 *
 *
 */

#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
   public:
    void dfs(int u, vector<vector<int>>& G, vector<int>& vis, bool& isCircle,
             vector<int>& res) {
        if (isCircle) return;
        vis[u] = -1;
        for (int i = 0; i < G[u].size(); i++) {
            if (vis[G[u][i]] != 1) {
                if (vis[G[u][i]] == 0) {
                    dfs(G[u][i], G, vis, isCircle, res);
                } else {
                    isCircle = true;
                    return;
                }
            }
        }
        vis[u] = 1;
        res.push_back(u);
    }

    // 出度 dfs
    // vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
    // {
    //     vector<vector<int>> G(numCourses, vector<int>());
    //     for (int i = 0; i < prerequisites.size(); i++) {
    //         int from = prerequisites[i][0];
    //         int to = prerequisites[i][1];
    //         G[from].push_back(to);
    //     }

    //     vector<int> res;
    //     bool isCircle = false;
    //     vector<int> vis(numCourses, 0);
    //     for (int i = 0; i < numCourses; i++) {
    //         if (!vis[i]) {
    //             dfs(i, G, vis, isCircle, res);
    //         }
    //     }

    //     if (!isCircle)
    //         return res;
    //     else
    //         return vector<int>();
    // }

    // kahn's algorithm
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> edges(numCourses, vector<int>{});
        vector<int> indegrees(numCourses, 0);
        deque<int> queue;
        for (auto p : prerequisites) {
            edges[p[1]].push_back(p[0]);
            indegrees[p[0]] += 1;
        }

        for (int i = 0; i < numCourses; i++) {
            if (indegrees[i] == 0) {
                queue.push_back(i);
            }
        }
        vector<int> res;
        while (!queue.empty()) {
            int u = queue.front();
            queue.pop_front();
            res.push_back(u);

            for (auto v : edges[u]) {
                indegrees[v] -= 1;
                if (indegrees[v] == 0) {
                    queue.push_back(v);
                }
            }
        }

        if (res.size() == numCourses) {
            return res;
        } else {
            return vector<int>{};
        }
    }
};
// @lc code=end

/*
 * [210] Course Schedule II
 *
 * https://leetcode.com/problems/course-schedule-ii/description/
 *
 * algorithms
 * Medium (30.37%)
 * Total Accepted:    91.8K
 * Total Submissions: 301.4K
 * Testcase Example:  '2\n[[1,0]]'
 *
 * There are a total of n courses you have to take, labeled from 0 to n-1.
 *
 * Some courses may have prerequisites, for example to take course 0 you have
 * to first take course 1, which is expressed as a pair: [0,1]
 *
 * Given the total number of courses and a list of prerequisite pairs, return
 * the ordering of courses you should take to finish all courses.
 *
 * There may be multiple correct orders, you just need to return one of them.
 * If it is impossible to finish all courses, return an empty array.
 *
 * Example 1:
 *
 *
 * Input: 2, [[1,0]]
 * Output: [0,1]
 * Explanation: There are a total of 2 courses to take. To take course 1 you
 * should have finished
 * course 0. So the correct course order is [0,1] .
 *
 * Example 2:
 *
 *
 * Input: 4, [[1,0],[2,0],[3,1],[3,2]]
 * Output: [0,1,2,3] or [0,2,1,3]
 * Explanation: There are a total of 4 courses to take. To take course 3 you
 * should have finished both
 * ⁠            courses 1 and 2. Both courses 1 and 2 should be taken after you
 * finished course 0.
 * So one correct course order is [0,1,2,3]. Another correct ordering is
 * [0,2,1,3] .
 *
 * Note:
 *
 *
 * The input prerequisites is a graph represented by a list of edges, not
 * adjacency matrices. Read more about how a graph is represented.
 * You may assume that there are no duplicate edges in the input
 * prerequisites.
 *
 *
 * Hints:
 *
 *
 * This problem is equivalent to finding the topological order in a directed
 * graph. If a cycle exists, no topological ordering exists and therefore it
 * will be impossible to take all courses.
 * Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera
 * explaining the basic concepts of Topological Sort.
 * Topological sort could also be done via BFS.
 *
 *
 */
class Solution {
public:
    void dfs(int u, vector<vector<int>>& G, vector<int>& vis, bool& isCircle, vector<int>& res){
        if(isCircle) return;
        vis[u] = -1;
        for(int i = 0; i < G[u].size(); i++){
            if(vis[G[u][i]] != 1){
                if(vis[G[u][i]] == 0){
                    dfs(G[u][i], G, vis, isCircle, res);
                }else{
                    isCircle = true;
                    return;
                }
            }
        }
        vis[u] = 1;
        res.push_back(u);
    }

    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> G(numCourses, vector<int>());
        for(int i = 0; i < prerequisites.size(); i++){
            int from = prerequisites[i].first;
            int to = prerequisites[i].second;
            G[from].push_back(to);
        }

        vector<int> res;
        bool isCircle = false;
        vector<int> vis(numCourses, 0);
        for(int i = 0;i < numCourses; i++){
            if(!vis[i]){
                dfs(i, G, vis, isCircle, res);
            }
        }

        if(!isCircle) return res;
        else return  vector<int>();
    }
};

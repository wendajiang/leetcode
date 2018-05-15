/*
 * [207] Course Schedule
 *
 * https://leetcode.com/problems/course-schedule/description/
 *
 * algorithms
 * Medium (33.83%)
 * Total Accepted:    125K
 * Total Submissions: 368.7K
 * Testcase Example:  '2\n[[1,0]]'
 *
 * There are a total of n courses you have to take, labeled from 0 to n-1.
 *
 * Some courses may have prerequisites, for example to take course 0 you have
 * to first take course 1, which is expressed as a pair: [0,1]
 *
 * Given the total number of courses and a list of prerequisite pairs, is it
 * possible for you to finish all courses?
 *
 * Example 1:
 *
 *
 * Input: 2, [[1,0]]
 * Output: true
 * Explanation: There are a total of 2 courses to take.
 * To take course 1 you should have finished course 0. So it is possible.
 *
 * Example 2:
 *
 *
 * Input: 2, [[1,0],[0,1]]
 * Output: false
 * Explanation: There are a total of 2 courses to take.
 * To take course 1 you should have finished course 0, and to take course 0 you
 * should
 * also have finished course 1. So it is impossible.
 *
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
 * This problem is equivalent to finding if a cycle exists in a directed graph.
 * If a cycle exists, no topological ordering exists and therefore it will be
 * impossible to take all courses.
 * Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera
 * explaining the basic concepts of Topological Sort.
 * Topological sort could also be done via BFS.
 *
 *
 */
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> G(numCourses, vector<int>());
        vector<int> du(numCourses, 0);
        for(int i = 0; i < prerequisites.size(); i++){
            int from = prerequisites[i].first;
            int to = prerequisites[i].second;
            G[from].push_back(to);
            du[to]++;
        }
        queue<int> Q;
        for(int i = 0; i < numCourses; i++){
            if(du[i] == 0) Q.push(i);
        }
        vector<int> res(numCourses, 0);
        int tot = 0;
        while(!Q.empty()){
            int cur = Q.front(); Q.pop();
            res[tot++] = cur;
            for(int i = 0; i < G[cur].size(); i++){
                du[G[cur][i]]--;
                if(du[G[cur][i]] == 0) Q.push(G[cur][i]);
            }
        }
        if(tot == numCourses) return true;
        else return  false;
    }
};

/*
 * [133] Clone Graph
 *
 * https://leetcode.com/problems/clone-graph/description/
 *
 * algorithms
 * Medium (25.18%)
 * Total Accepted:    148.7K
 * Total Submissions: 590.7K
 * Testcase Example:  '{}'
 *
 *
 * Clone an undirected graph. Each node in the graph contains a label and a
 * list of its neighbors.
 *
 *
 *
 *
 * OJ's undirected graph serialization:
 *
 *
 * Nodes are labeled uniquely.
 *
 *
 * We use # as a separator for each node, and , as a separator for node label
 * and each neighbor of the node.
 *
 *
 *
 *
 * As an example, consider the serialized graph {0,1,2#1,2#2,2}.
 *
 *
 *
 * The graph has a total of three nodes, and therefore contains three parts as
 * separated by #.
 *
 * First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
 * Second node is labeled as 1. Connect node 1 to node 2.
 * Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming
 * a self-cycle.
 *
 *
 *
 *
 * Visually, the graph looks like the following:
 *
 * ⁠      1
 * ⁠     / \
 * ⁠    /   \
 * ⁠   0 --- 2
 * ⁠        / \
 * ⁠        \_/
 *
 *
 *
 *
 */
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> mp;


    // //DFS
    // UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    //     if(!node) return NULL;
    //     if(mp.find(node) == mp.end()){
    //         mp[node] = new UndirectedGraphNode(node->label);
    //         for(auto neigh : node->neighbors){
    //             mp[node]->neighbors.push_back(cloneGraph(neigh));
    //         }
    //     }
    //     return mp[node];
    // }

    //BFS
    UndirectedGraphNode* cloneGraph(UndirectedGraphNode* node){
        if(!node) return NULL;
        UndirectedGraphNode* copy = new UndirectedGraphNode(node->label);
        mp[node] = copy;
        queue<UndirectedGraphNode*> Q;
        Q.push(node);
        while(!Q.empty()){
            UndirectedGraphNode* cur = Q.front(); Q.pop();
            for(auto neigh : cur->neighbors){
                if(mp.find(neigh) == mp.end()){
                    UndirectedGraphNode* neigh_copy = new UndirectedGraphNode(neigh->label);
                    mp[neigh] = neigh_copy;
                    Q.push(neigh);
                }
                mp[cur]->neighbors.push_back(mp[neigh]);
            }
        }
        return copy;
    }
};

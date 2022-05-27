/*
 * [111] Minimum Depth of Binary Tree
 *
 * https://leetcode.com/problems/minimum-depth-of-binary-tree
 *
 * Easy (32.95%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[]'
 *
 * Given a binary tree, find its minimum depth.
 *
 * The minimum depth is the number of nodes along the shortest path from the
 * root node down to the nearest leaf node.
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        int res = 0;
        queue<TreeNode*> Q;
        Q.push(root);
        while(Q.size()){
            res++;
            for(int i = 0, n = Q.size(); i < n; i++){
                TreeNode* node = Q.front();
                Q.pop();
                if(!node->left && !node->right) return res;
                if(node->left) Q.push(node->left);
                if(node->right) Q.push(node->right);
            }
        }
        return res;
    }
};

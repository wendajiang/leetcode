/*
 * [543] Diameter of Binary Tree
 *
 * https://leetcode.com/problems/diameter-of-binary-tree
 *
 * Easy (43.50%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[1,2,3,4,5]'
 *
 *
 * Given a binary tree, you need to compute the length of the diameter of the
 * tree. The diameter of a binary tree is the length of the longest path
 * between any two nodes in a tree. This path may or may not pass through the
 * root.
 *
 *
 *
 * Example:
 * Given a binary tree
 *
 * ⁠         1
 * ⁠        / \
 * ⁠       2   3
 * ⁠      / \
 * ⁠     4   5
 *
 *
 *
 * Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].
 *
 *
 * Note:
 * The length of path between two nodes is represented by the number of edges
 * between them.
 *
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
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int maxV = INT_MIN;
        depthNode(root, maxV);
        return maxV;
    }
    int depthNode(TreeNode* node, int& maxV){
        if(!node) return 0;
        int leftDepth = depthNode(node->left, maxV);
        int rightDepth = depthNode(node->right, maxV);
        maxV = std::max(maxV, leftDepth + rightDepth);
        return 1 + std::max(leftDepth, rightDepth);
    }

};

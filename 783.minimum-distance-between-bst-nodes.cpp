/*
 * [799] Minimum Distance Between BST Nodes
 *
 * https://leetcode.com/problems/minimum-distance-between-bst-nodes/description/
 *
 * algorithms
 * Easy (47.24%)
 * Total Accepted:    8.3K
 * Total Submissions: 17.5K
 * Testcase Example:  '[4,2,6,1,3,null,null]'
 *
 * Given a Binary Search Tree (BST) with the root node root, return the minimum
 * difference between the values of any two different nodes in the tree.
 *
 * Example :
 *
 *
 * Input: root = [4,2,6,1,3,null,null]
 * Output: 1
 * Explanation:
 * Note that root is a TreeNode object, not an array.
 *
 * The given tree [4,2,6,1,3,null,null] is represented by the following
 * diagram:
 *
 * ⁠         4
 * ⁠       /   \
 * ⁠     2      6
 * ⁠    / \
 * ⁠   1   3
 *
 * while the minimum difference in this tree is 1, it occurs between node 1 and
 * node 2, also between node 3 and node 2.
 *
 *
 * Note:
 *
 *
 * The size of the BST will be between 2 and 100.
 * The BST is always valid, each node's value is an integer, and each node's
 * value is different.
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
    void inorderTraversal(TreeNode* node, TreeNode*& pre, int &minV){
        if(!node)return;
        inorderTraversal(node->left, pre, minV);
        if(pre && node->val - pre->val < minV){
            minV = node->val - pre->val;
        }
        pre = node;
        inorderTraversal(node->right, pre, minV);
    }

    int minDiffInBST(TreeNode* root) {
        int minV = INT_MAX;
        TreeNode* pre = nullptr;
        inorderTraversal(root, pre, minV);
        return minV;
    }
};

/*
 * [98] Validate Binary Search Tree
 *
 * https://leetcode.com/problems/validate-binary-search-tree
 *
 * Medium (23.16%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[2,1,3]'
 *
 *
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 *
 *
 *
 * Assume a BST is defined as follows:
 *
 * The left subtree of a node contains only nodes with keys less than the
 * node's key.
 * The right subtree of a node contains only nodes with keys greater than the
 * node's key.
 * Both the left and right subtrees must also be binary search trees.
 *
 *
 *
 * Example 1:
 *
 * ⁠   2
 * ⁠  / \
 * ⁠ 1   3
 *
 * Binary tree [2,1,3], return true.
 *
 *
 * Example 2:
 *
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   3
 *
 * Binary tree [1,2,3], return false.
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
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return true;
        vector<int> nodes;
        inorderTraversal(root, nodes);
        for(int i = 0; i < nodes.size() - 1; i++){
            if(nodes[i] >= nodes[i + 1])
                return false;
        }
        return true;
    }
    void inorderTraversal(TreeNode* node, vector<int>& nodes){
        if(!node) return;
        inorderTraversal(node->left, nodes);
        nodes.push_back(node->val);
        inorderTraversal(node->right, nodes);
    }
};

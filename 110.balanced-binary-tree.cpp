/*
 * [110] Balanced Binary Tree
 *
 * https://leetcode.com/problems/balanced-binary-tree
 *
 * Easy (37.26%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[]'
 *
 * Given a binary tree, determine if it is height-balanced.
 *
 *
 *
 * For this problem, a height-balanced binary tree is defined as a binary tree
 * in which the depth of the two subtrees of every node never differ by more
 * than 1.
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
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return true;
        int val = getBalance(root);
        if(val == -1)
            return false;
        return true;
    }
    int getBalance(TreeNode *node){
        if(node == NULL)
            return 0;
        int left = getBalance(node->left);
        if(left == -1) return -1;
        int right = getBalance(node->right);
        if(right == -1) return -1;
        if(std::abs(left-right) > 1){
            return -1;
        }
        else{
            return left > right ? left + 1 : right + 1;
        }
    }
};

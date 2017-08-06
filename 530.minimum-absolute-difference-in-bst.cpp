/*
 * [530] Minimum Absolute Difference in BST
 *
 * https://leetcode.com/problems/minimum-absolute-difference-in-bst
 *
 * Easy (47.00%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[1,null,3,2]'
 *
 * Given a binary search tree with non-negative values, find the minimum
 * absolute difference between values of any two nodes.
 *
 *
 * Example:
 *
 * Input:
 *
 * ⁠  1
 * ⁠   \
 * ⁠    3
 * ⁠   /
 * ⁠  2
 *
 * Output:
 * 1
 *
 * Explanation:
 * The minimum absolute difference is 1, which is the difference between 2 and
 * 1 (or between 2 and 3).
 *
 *
 *
 *
 * Note:
 * There are at least two nodes in this BST.
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
    int getMinimumDifference(TreeNode* root) {
        int minV = INT_MAX;
        TreeNode* pre = nullptr;
        inorderTraversal(root, pre, minV);
        return minV;
    }
    void inorderTraversal(TreeNode* node, TreeNode*& pre, int &minV){
        if(!node)return;
        inorderTraversal(node->left, pre, minV);
        if(pre && node->val - pre->val < minV){
            minV = node->val - pre->val;
        }
        pre = node;
        inorderTraversal(node->right, pre, minV);
    }

};

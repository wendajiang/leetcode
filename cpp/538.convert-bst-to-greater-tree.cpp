/*
 * [538] Convert BST to Greater Tree
 *
 * https://leetcode.com/problems/convert-bst-to-greater-tree
 *
 * Easy (51.02%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[5,2,13]'
 *
 * Given a Binary Search Tree (BST), convert it to a Greater Tree such that
 * every key of the original BST is changed to the original key plus sum of all
 * keys greater than the original key in BST.
 *
 *
 * Example:
 *
 * Input: The root of a Binary Search Tree like this:
 * ⁠             5
 * ⁠           /   \
 * ⁠          2     13
 *
 * Output: The root of a Greater Tree like this:
 * ⁠            18
 * ⁠           /   \
 * ⁠         20     13
 *
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
    TreeNode* convertBST(TreeNode* root) {
        if(root == nullptr) return nullptr;
        TreeNode* pre = nullptr;
        convert(root, pre);
        return root;
    }
    void convert(TreeNode* node, TreeNode*& pre){
        if(node == nullptr)return;
        convert(node->right, pre);
        if(pre)
            node->val = node->val + pre->val;
        pre = node;
        convert(node->left, pre);
    }
};

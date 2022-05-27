/*
 * @lc app=leetcode id=671 lang=cpp
 *
 * [671] Second Minimum Node In a Binary Tree
 *
 * https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/description/
 *
 * algorithms
 * Easy (42.76%)
 * Likes:    946
 * Dislikes: 1231
 * Total Accepted:    113.3K
 * Total Submissions: 263.2K
 * Testcase Example:  '[2,2,5,null,null,5,7]'
 *
 * Given a non-empty special binary tree consisting of nodes with the
 * non-negative value, where each node in this tree has exactly two or zero
 * sub-node. If the node has two sub-nodes, then this node's value is the
 * smaller value among its two sub-nodes. More formally, the property root.val
 * = min(root.left.val, root.right.val) always holds.
 *
 * Given such a binary tree, you need to output the second minimum value in the
 * set made of all the nodes' value in the whole tree.
 *
 * If no such second minimum value exists, output -1 instead.
 *
 *
 *
 *
 * Example 1:
 *
 *
 * Input: root = [2,2,5,null,null,5,7]
 * Output: 5
 * Explanation: The smallest value is 2, the second smallest value is 5.
 *
 *
 * Example 2:
 *
 *
 * Input: root = [2,2,2]
 * Output: -1
 * Explanation: The smallest value is 2, but there isn't any second smallest
 * value.
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [1, 25].
 * 1 <= Node.val <= 2^31 - 1
 * root.val == min(root.left.val, root.right.val) for each internal node of the
 * tree.
 *
 *
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        if (!root->left) return -1;
        int left = (root->left->val == root->val) ? findSecondMinimumValue(root->left) : root->left->val;
        int right = (root->right->val == root->val) ? findSecondMinimumValue(root->right) : root->right->val;
        return (left == -1 || right == -1) ? max(left, right) : min(left, right);
    }
    // int findSecondMinimumValue(TreeNode* root) {
        // return findCore(root, root->val);
    // }
private:
    int findCore(TreeNode* node, int f) {
        if (!node) return -1;
        if (node->val != f) return node->val;
        int left = findCore(node->left, f);
        int right = findCore(node->right, f);
        return (left == -1 || right == -1) ? max(left, right) : min(left, right);
    }
};
// @lc code=end

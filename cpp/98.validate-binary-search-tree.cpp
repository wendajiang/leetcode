/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
 *
 * https://leetcode.com/problems/validate-binary-search-tree/description/
 *
 * algorithms
 * Medium (29.77%)
 * Likes:    9851
 * Dislikes: 892
 * Total Accepted:    1.4M
 * Total Submissions: 4.6M
 * Testcase Example:  '[2,1,3]'
 *
 * Given the root of a binary tree, determine if it is a valid binary search
 * tree (BST).
 *
 * A valid BST is defined as follows:
 *
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
 *
 * Input: root = [2,1,3]
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: root = [5,1,4,null,null,3,6]
 * Output: false
 * Explanation: The root node's value is 5 but its right child's value is
 * 4.
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [1, 10^4].
 * -2^31 <= Node.val <= 2^31 - 1
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

// @lc code=start

class Solution {
   public:
    bool isValidBST(TreeNode *root) {
        if (nullptr == root) {
            return true;
        }
        prev = nullptr;
        return inorderTravel(root);
    }

    bool inorderTravel(TreeNode *node) {
        if (nullptr == node) return true;
        if (!inorderTravel(node->left)) return false;
        if (prev) {
            if (prev->val >= node->val) {
                return false;
            }
        }
        prev = node;
        return inorderTravel(node->right);
    }

    // basic collect inorder vector, and compare is so easy

   private:
    TreeNode *prev;
};
// @lc code=end

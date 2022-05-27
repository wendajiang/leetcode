/*
 * @lc app=leetcode id=1080 lang=cpp
 *
 * [1080] Insufficient Nodes in Root to Leaf Paths
 *
 * https://leetcode.com/problems/insufficient-nodes-in-root-to-leaf-paths/description/
 *
 * algorithms
 * Medium (49.68%)
 * Likes:    219
 * Dislikes: 367
 * Total Accepted:    16.5K
 * Total Submissions: 33.3K
 * Testcase Example:  '[1,2,3,4,-99,-99,7,8,9,-99,-99,12,13,-99,14]\n1'
 *
 * Given the root of a binary tree, consider all root to leaf paths: paths from
 * the root to any leaf.  (A leaf is a node with no children.)
 * 
 * A node is insufficient if every such root to leaf path intersecting this
 * node has sum strictly less than limit.
 * 
 * Delete all insufficient nodes simultaneously, and return the root of the
 * resulting binary tree.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * Input: root = [1,2,3,4,-99,-99,7,8,9,-99,-99,12,13,-99,14], limit = 1
 * 
 * Output: [1,2,3,4,null,null,7,8,9,null,14]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * Input: root = [5,4,8,11,null,17,4,7,1,null,null,5,3], limit = 22
 * 
 * Output: [5,4,8,11,null,17,4,7,null,null,null,5]
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * 
 * Input: root = [1,2,-3,-5,null,4,null], limit = -1
 * 
 * Output: [1,null,-3,4]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The given tree will have between 1 and 5000 nodes.
 * -10^5 <= node.val <= 10^5
 * -10^9 <= limit <= 10^9
 * 
 * 
 * 
 * 
 * 
 * 
 */
#include <bits/stdc++.h>
using namespace std;

/**
 * @brief 
 * (递归) O(n)
 * 采用自底向上的删除策略。
 * 如果某个结点是叶子结点，则判断到根结点的路径是否小于 limit。如果小于，则直接将其变为 NULL，然后回溯。
 * 如果不是叶子结点，则递归删除左儿子结点和（或）右儿子结点。如果当前结点变为了叶子结点，也将其变为 NULL，因为这代表着所有 “根-叶” 路径都小于 limit。
 * 
 * 时间复杂度
 * 每个结点遍历一次，故时间复杂度为 O(n)O(n)。
 * 
 * 空间复杂度
 * 递归需要栈空间，故空间复杂度为 O(h)O(h)，hh 为树的最大高度。
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
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        cut(root, limit, root->val);
        return root;
    }

    void cut(TreeNode* &node, int limit, int sum) {
        if (node->left == nullptr && node->right == nullptr) {
            if (sum < limit)
                node = nullptr;
            return;
        }
        if (node->left) {
            cut(node->left, limit, sum + node->left->val);
        }
        if (node->right) {
            cut(node->right, limit, sum + node->right->val);
        }
        if (node->left == nullptr && node->right == nullptr) {
            node = nullptr;
        }
    }
};
// @lc code=end


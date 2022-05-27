/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
 *
 * https://leetcode.com/problems/binary-tree-maximum-path-sum/description/
 *
 * algorithms
 * Hard (35.18%)
 * Likes:    4889
 * Dislikes: 361
 * Total Accepted:    449.5K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,2,3]'
 *
 * Given a non-empty binary tree, find the maximum path sum.
 *
 * For this problem, a path is defined as any node sequence from some starting
 * node to any node in the tree along the parent-child connections. The path
 * must contain at least one node and does not need to go through the root.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,2,3]
 * Output: 6
 *
 *
 * Example 2:
 *
 *
 * Input: root = [-10,9,20,null,null,15,7]
 * Output: 42
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [0, 3 * 10^4].
 * -1000 <= Node.val <= 1000
 *
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 */
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int max_res = INT_MIN;
    int maxPathSum(TreeNode *root) {
        maxGain(root);
        return max_res;
    }

    int maxGain(TreeNode* node) {
        if (!node) return 0;

        int left_gain = max(maxGain(node->left), 0);
        int right_gain = max(maxGain(node->right), 0);

        max_res = max(max_res, node->val + left_gain + right_gain);

        return node->val + max(left_gain, right_gain);
    }
};
// @lc code=end

/*
 * @lc app=leetcode id=687 lang=cpp
 *
 * [687] Longest Univalue Path
 *
 * https://leetcode.com/problems/longest-univalue-path/description/
 *
 * algorithms
 * Medium (38.29%)
 * Likes:    2587
 * Dislikes: 579
 * Total Accepted:    123.6K
 * Total Submissions: 322.7K
 * Testcase Example:  '[5,4,5,1,1,5]'
 *
 * Given the root of a binary tree, return the length of the longest path,
 * where each node in the path has the same value. This path may or may not
 * pass through the root.
 *
 * The length of the path between two nodes is represented by the number of
 * edges between them.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [5,4,5,1,1,5]
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: root = [1,4,5,4,4,5]
 * Output: 2
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [0, 10^4].
 * -1000 <= Node.val <= 1000
 * The depth of the tree will not exceed 1000.
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

// https://zxi.mytechroad.com/blog/tree/leetcode-687-longest-univalue-path/
// https://www.cnblogs.com/grandyang/p/7636259.html
class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        if (root == nullptr) return 0;
        int ans = 0;
        univaluePath(root, &ans);
        return ans;
    }
private:
    int univaluePath(TreeNode* node, int *ans) {
        if (node == nullptr) return 0;
        int l = univaluePath(node->left, ans);
        int r = univaluePath(node->right, ans);
        int pl = 0;
        int pr = 0;
        if (node->left && node->val == node->left->val) pl = l + 1;
        if (node->right && node->val == node->right->val) pr = r + 1;
        *ans = max(*ans, pl + pr);
        return max(pl, pr);
    }
};
// @lc code=end

/*
 * @lc app=leetcode id=993 lang=cpp
 *
 * [993] Cousins in Binary Tree
 *
 * https://leetcode.com/problems/cousins-in-binary-tree/description/
 *
 * algorithms
 * Easy (52.44%)
 * Likes:    1827
 * Dislikes: 106
 * Total Accepted:    162K
 * Total Submissions: 308.9K
 * Testcase Example:  '[1,2,3,4]\n4\n3'
 *
 * Given the root of a binary tree with unique values and the values of two
 * different nodes of the tree x and y, return true if the nodes corresponding
 * to the values x and y in the tree are cousins, or false otherwise.
 *
 * Two nodes of a binary tree are cousins if they have the same depth with
 * different parents.
 *
 * Note that in a binary tree, the root node is at the depth 0, and children of
 * each depth k node are at the depth k + 1.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,2,3,4], x = 4, y = 3
 * Output: false
 *
 *
 * Example 2:
 *
 *
 * Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
 * Output: true
 *
 *
 * Example 3:
 *
 *
 * Input: root = [1,2,3,null,4], x = 2, y = 3
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [2, 100].
 * 1 <= Node.val <= 100
 * Each node has a unique value.
 * x != y
 * x and y are exist in the tree.
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
    bool isCousins(TreeNode* root, int x, int y) {
        if (!root) return true;
        if (root->val == x || root->val == y) return false;
        dfs(root, nullptr, 0);
        if (mp_depth_p[x].first == mp_depth_p[y].first
            && mp_depth_p[x].second != mp_depth_p[y].second) {
            return true;
        } else {
            return false;
        }
    }

private:
    unordered_map<int, pair<int, int>> mp_depth_p;
    void dfs(TreeNode *node, TreeNode *parent, int depth) {
        if (!parent && node) {
            mp_depth_p[node->val] = make_pair(depth, -1);
        } else if (parent && node) {
            mp_depth_p[node->val] = make_pair(depth, parent->val);
        }
        if (node->left) dfs(node->left, node, depth + 1);
        if (node->right) dfs(node->right, node, depth + 1);

    }
};
// @lc code=end

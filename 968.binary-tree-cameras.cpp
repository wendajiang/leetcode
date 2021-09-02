/*
 * @lc app=leetcode id=968 lang=cpp
 *
 * [968] Binary Tree Cameras
 *
 * https://leetcode.com/problems/binary-tree-cameras/description/
 *
 * algorithms
 * Hard (41.04%)
 * Likes:    2076
 * Dislikes: 30
 * Total Accepted:    52.3K
 * Total Submissions: 127.4K
 * Testcase Example:  '[0,0,null,0,0]'
 *
 * You are given the root of a binary tree. We install cameras on the tree
 * nodes where each camera at a node can monitor its parent, itself, and its
 * immediate children.
 *
 * Return the minimum number of cameras needed to monitor all nodes of the
 * tree.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [0,0,null,0,0]
 * Output: 1
 * Explanation: One camera is enough to monitor all nodes if placed as shown.
 *
 *
 * Example 2:
 *
 *
 * Input: root = [0,0,null,0,null,0,null,null,0]
 * Output: 2
 * Explanation: At least two cameras are needed to monitor all nodes of the
 * tree. The above image shows one of the valid configurations of camera
 * placement.
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [1, 1000].
 * Node.val == 0
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
    int minCameraCover(TreeNode* root) {
        if (dfs(root) == State::NONE) ans++;
        return ans;
    }
private:
    enum class State {
        NONE = 0,
        COVERED = 1,
        CAMERA = 2
    };

    int ans = 0;
    State dfs(TreeNode *node) {
        if (!node) return State::COVERED;
        State l = dfs(node->left);
        State r = dfs(node->right);
        if (l == State::NONE || r == State::NONE) {
            ++ans;
            return State::CAMERA;
        }
        if (l == State::CAMERA || r == State::CAMERA) {
            return State::COVERED;
        }
        return State::NONE;
    }
};
// @lc code=end

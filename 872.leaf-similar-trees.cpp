/*
 * @lc app=leetcode id=872 lang=cpp
 *
 * [872] Leaf-Similar Trees
 *
 * https://leetcode.com/problems/leaf-similar-trees/description/
 *
 * algorithms
 * Easy (64.61%)
 * Likes:    1368
 * Dislikes: 53
 * Total Accepted:    139.3K
 * Total Submissions: 215.6K
 * Testcase Example:  '[3,5,1,6,2,9,8,null,null,7,4]\n' +
  '[3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]'
 *
 * Consider all the leaves of a binary tree, from left to right order, the
 * values of those leaves form a leaf value sequence.
 *
 *
 *
 * For example, in the given tree above, the leaf value sequence is (6, 7, 4,
 * 9, 8).
 *
 * Two binary trees are considered leaf-similar if their leaf value sequence is
 * the same.
 *
 * Return true if and only if the two given trees with head nodes root1 and
 * root2 are leaf-similar.
 *
 *
 * Example 1:
 *
 *
 * Input: root1 = [3,5,1,6,2,9,8,null,null,7,4], root2 =
 * [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: root1 = [1], root2 = [1]
 * Output: true
 *
 *
 * Example 3:
 *
 *
 * Input: root1 = [1], root2 = [2]
 * Output: false
 *
 *
 * Example 4:
 *
 *
 * Input: root1 = [1,2], root2 = [2,2]
 * Output: true
 *
 *
 * Example 5:
 *
 *
 * Input: root1 = [1,2,3], root2 = [1,3,2]
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in each tree will be in the range [1, 200].
 * Both of the given trees will have values in the range [0, 200].
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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr) return true;
        if (root1 == nullptr || root2 == nullptr) return false;

        vector<int> seq1, seq2;
        travel(root1, seq1);
        travel(root2, seq2);

        if (seq1.size() != seq2.size()) return false;

        for (int i = 0; i < seq1.size(); i++) {
            if (seq1[i] != seq2[i]) return false;
        }
        return true;
    }

private:
    void travel(TreeNode* node, vector<int> &ans) {
        if (node->left == nullptr && node->right == nullptr) {
            ans.push_back(node->val);
            return;
        }
        if (node->left) travel(node->left, ans);
        if (node->right) travel(node->right, ans);
    }
};
// @lc code=end

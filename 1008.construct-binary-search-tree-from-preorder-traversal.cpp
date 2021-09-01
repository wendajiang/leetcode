/*
 * @lc app=leetcode id=1008 lang=cpp
 *
 * [1008] Construct Binary Search Tree from Preorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/
 *
 * algorithms
 * Medium (79.00%)
 * Likes:    2354
 * Dislikes: 52
 * Total Accepted:    178.4K
 * Total Submissions: 225.9K
 * Testcase Example:  '[8,5,1,7,10,12]'
 *
 * Given an array of integers preorder, which represents the preorder traversal
 * of a BST (i.e., binary search tree), construct the tree and return its
 * root.
 *
 * It is guaranteed that there is always possible to find a binary search tree
 * with the given requirements for the given test cases.
 *
 * A binary search tree is a binary tree where for every node, any descendant
 * of Node.left has a value strictly less than Node.val, and any descendant of
 * Node.right has a value strictly greater than Node.val.
 *
 * A preorder traversal of a binary tree displays the value of the node first,
 * then traverses Node.left, then traverses Node.right.
 *
 *
 * Example 1:
 *
 *
 * Input: preorder = [8,5,1,7,10,12]
 * Output: [8,5,10,1,7,null,12]
 *
 *
 * Example 2:
 *
 *
 * Input: preorder = [1,3]
 * Output: [1,null,3]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= preorder.length <= 100
 * 1 <= preorder[i] <= 10^8
 * All the values of preorder are unique.
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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return dfs(preorder, 0, preorder.size() - 1);
    }
private:
    TreeNode* dfs(vector<int> &preorder, int start, int end) {
        if (start > end) {
            return nullptr;
        }
        int rootnum = preorder[start];
        TreeNode *root = new TreeNode(rootnum);

        int cur = start;
        for (; cur <= end; cur++) {
            if (preorder[cur] > rootnum) {
                break;
            }
        }
        root->left = dfs(preorder, start + 1, cur - 1);
        root->right = dfs(preorder, cur, end);
        return root;
    }
};
// @lc code=end

/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-preorder-traversal/description/
 *
 * algorithms
 * Medium (53.39%)
 * Likes:    1199
 * Dislikes: 51
 * Total Accepted:    437.9K
 * Total Submissions: 810.1K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the preorder traversal of its nodes' values.
 * 
 * Example:
 * 
 * 
 * Input: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * Output: [1,2,3]
 * 
 * 
 * Follow up: Recursive solution is trivial, could you do it iteratively?
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> res;
        if (!root) return res;
        while (root || !st.empty()) {
            while(root) {
                res.push_back(root->val);
                st.push(root);
                root = root->left;
            }
            if (!st.empty()) {
                root = st.top();
                st.pop();
                root = root->right;
            }
        }
        return res;
        
    }
    vector<int> preorderTraversal2(TreeNode* root) {
        vector<int> res;
        if (root) {
            preorder(root, res);
        }
        return res;
    }
    void preorder(TreeNode* node, vector<int>& res) {
        if (node) {
            res.push_back(node->val);
            if (node->left) preorder(node->left, res);
            if (node->right) preorder(node->right, res);
        }
    }
};
// @lc code=end

/*
 * [102] Binary Tree Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal
 *
 * Medium (39.19%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the level order traversal of its nodes' values.
 * (ie, from left to right, level by level).
 *
 *
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 *
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 *
 *
 *
 * return its level order traversal as:
 *
 * [
 * ⁠ [3],
 * ⁠ [9,20],
 * ⁠ [15,7]
 * ]
 *
 *
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) return {};
        vector<vector<int>> res;
        vector<int> solution;
        queue<TreeNode *> Q;
        Q.push(root);
        while(!Q.empty()){
            int count = Q.size();
            while(count){
                TreeNode* tmp = Q.front();
                Q.pop();
                solution.push_back(tmp->val);
                if(tmp->left) Q.push(tmp->left);
                if(tmp->right) Q.push(tmp->right);
                count--;
            }
            res.push_back(solution);
            solution.erase(solution.begin(), solution.end());
        }
        return res;
    }
};

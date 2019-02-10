/*
 * [113] Path Sum II
 *
 * https://leetcode.com/problems/path-sum-ii
 *
 * Medium (33.21%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,5,1]\n22'
 *
 *
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's
 * sum equals the given sum.
 *
 *
 * For example:
 * Given the below binary tree and sum = 22,
 *
 * ⁠             5
 * ⁠            / \
 * ⁠           4   8
 * ⁠          /   / \
 * ⁠         11  13  4
 * ⁠        /  \    / \
 * ⁠       7    2  5   1
 *
 *
 *
 * return
 *
 * [
 * ⁠  [5,4,11,2],
 * ⁠  [5,8,4,5]
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root == NULL) return {};
        vector<vector<int>> res;
        vector<int> solution;
        pathSum(root, 0, sum, solution, res);
        return res;
    }

    void pathSum(TreeNode* root, int sum, int target, vector<int>& solution, vector<vector<int>>& res){
        solution.push_back(root->val);
        sum += root->val;
        if(sum == target && root->left == NULL && root->right == NULL){
            res.push_back(solution);
        }else{
            if(root->left){
                pathSum(root->left, sum, target, solution, res);
            }
            if(root->right){
                pathSum(root->right, sum, target, solution, res);
            }
        }
        solution.pop_back();
        return;
    }
};

/*
 * [103] Binary Tree Zigzag Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal
 *
 * Medium (34.15%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the zigzag level order traversal of its nodes'
 * values. (ie, from left to right, then right to left for the next level and
 * alternate between).
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
 * return its zigzag level order traversal as:
 *
 * [
 * ⁠ [3],
 * ⁠ [20,9],
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
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
        bool flag = true;
        for(int i = 0; i < res.size(); i++){
            if(flag = 1 - flag){
                zigzagChange(res[i]);
            }
        }
        return res;
    }
    void zigzagChange(vector<int> & solution){
        int start = 0;
        int end = solution.size() - 1;
        while(start < end){
            int tmp = solution[start];
            solution[start] = solution[end];
            solution[end] = tmp;
            start++;
            end--;
        }
    }
};

/*
 * [637] Average of Levels in Binary Tree
 *
 * https://leetcode.com/problems/average-of-levels-in-binary-tree
 *
 * Easy (58.36%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[3,9,20,15,7]'
 *
 * Given a non-empty binary tree, return the average value of the nodes on each
 * level in the form of an array.
 *
 * Example 1:
 *
 * Input:
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * Output: [3, 14.5, 11]
 * Explanation:
 * The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on
 * level 2 is 11. Hence return [3, 14.5, 11].
 *
 *
 *
 * Note:
 *
 * The range of node's value is in the range of 32-bit signed integer.
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
    vector<double> averageOfLevels(TreeNode* root) {
        if(root == nullptr) return {};
        vector<vector<int>> res;
        vector<int> solution;
        queue<TreeNode *> Q;
        Q.push(root);
        vector<double> average;
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
        for(vector<int> e : res){
            double sum = 0.0;
            for(auto x : e){
                sum += x;
            }
            sum = (double)(sum / e.size());
            average.push_back(sum);
        }
        return average;
    }
};

/*
 * @lc app=leetcode id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
 *
 * https://leetcode.com/problems/sum-root-to-leaf-numbers/description/
 *
 * algorithms
 * Medium (44.76%)
 * Likes:    1004
 * Dislikes: 30
 * Total Accepted:    225.6K
 * Total Submissions: 495K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a binary tree containing digits from 0-9 only, each root-to-leaf path
 * could represent a number.
 * 
 * An example is the root-to-leaf path 1->2->3 which represents the number
 * 123.
 * 
 * Find the total sum of all root-to-leaf numbers.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3]
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   3
 * Output: 25
 * Explanation:
 * The root-to-leaf path 1->2 represents the number 12.
 * The root-to-leaf path 1->3 represents the number 13.
 * Therefore, sum = 12 + 13 = 25.
 * 
 * Example 2:
 * 
 * 
 * Input: [4,9,0,5,1]
 * ⁠   4
 * ⁠  / \
 * ⁠ 9   0
 * / \
 * 5   1
 * Output: 1026
 * Explanation:
 * The root-to-leaf path 4->9->5 represents the number 495.
 * The root-to-leaf path 4->9->1 represents the number 491.
 * The root-to-leaf path 4->0 represents the number 40.
 * Therefore, sum = 495 + 491 + 40 = 1026.
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
    int square(int base, int n) {
        int res = 1;
        for (int i = 0; i < n; i++) {
            res *= base;
        }
        return res;
    }
    int sumNumbers(TreeNode* root) {
        if (root == NULL) 
            return 0;
        vector<vector<int>> collection;
        vector<int> path;
        dfs(root, collection, path);
        int sum = 0;
        for (int i = 0; i < collection.size(); i++) {
            int len = collection[i].size();
            int num = 0;
            for (int j = 0; j < collection[i].size(); j++) {
                if (collection[i][j] != 0)
                    num += (square(10, (len - j - 1)) * collection[i][j]);
            }
            sum += num;
        }
        return sum;

    }

    void dfs(TreeNode* root, vector<vector<int>>& c, vector<int> path) {
        if (!root) return;
        path.push_back(root->val);
        if (root->left == NULL && root->right == NULL) {
            c.push_back(path);
            return;
        }
        if (root->left) dfs(root->left, c, path);
        if (root->right) dfs(root->right, c, path);

        
    }
};
// @lc code=end

/*
 * @lc app=leetcode id=1609 lang=cpp
 *
 * [1609] Even Odd Tree
 *
 * https://leetcode.com/problems/even-odd-tree/description/
 *
 * algorithms
 * Medium (53.97%)
 * Likes:    177
 * Dislikes: 11
 * Total Accepted:    12.5K
 * Total Submissions: 23.1K
 * Testcase Example:  '[1,10,4,3,null,7,9,12,8,6,null,null,2]'
 *
 * A binary tree is named Even-Odd if it meets the following conditions:
 * 
 * 
 * The root of the binary tree is at level index 0, its children are at level
 * index 1, their children are at level index 2, etc.
 * For every even-indexed level, all nodes at the level have odd integer values
 * in strictly increasing order (from left to right).
 * For every odd-indexed level, all nodes at the level have even integer values
 * in strictly decreasing order (from left to right).
 * 
 * 
 * Given the root of a binary tree, return true if the binary tree is Even-Odd,
 * otherwise return false.
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: root = [1,10,4,3,null,7,9,12,8,6,null,null,2]
 * Output: true
 * Explanation: The node values on each level are:
 * Level 0: [1]
 * Level 1: [10,4]
 * Level 2: [3,7,9]
 * Level 3: [12,8,6,2]
 * Since levels 0 and 2 are all odd and increasing, and levels 1 and 3 are all
 * even and decreasing, the tree is Even-Odd.
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: root = [5,4,2,3,3,7]
 * Output: false
 * Explanation: The node values on each level are:
 * Level 0: [5]
 * Level 1: [4,2]
 * Level 2: [3,3,7]
 * Node values in the level 2 must be in strictly increasing order, so the tree
 * is not Even-Odd.
 * 
 * 
 * Example 3:
 * 
 * 
 * 
 * 
 * Input: root = [5,9,1,3,5,7]
 * Output: false
 * Explanation: Node values in the level 1 should be even integers.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: root = [1]
 * Output: true
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: root = [11,8,6,1,3,9,11,30,20,18,16,12,10,4,2,17]
 * Output: true
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [1, 10^5].
 * 1 <= Node.val <= 10^6
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

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        if (root == nullptr) return true;
        vector<TreeNode*> collect;
        int level = 0;
        collect.push_back(root);
        int l = 0, r = collect.size();
        while(l < r) {
            bool is_odd = (level & 0x1 != 0);
            for (int i = l; i < r; i++) {
                TreeNode* cur = collect[i];
                if (is_odd) { // odd level 
                    if ((cur->val & 0x1) != 0) return false;
                    if (i != l && cur->val >= collect[i - 1]->val) return false;
                }
                else { // even level
                    if ((cur->val & 0x1) == 0) return false;
                    if (i != l && cur->val <= collect[i - 1]->val) return false;
                }
                if (cur->left) collect.push_back(cur->left);
                if (cur->right) collect.push_back(cur->right);
            }
            l = r;
            r = collect.size();
            level ++;
        }
        return true;
    }
};
// @lc code=end


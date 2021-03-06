/*
 * @lc app=leetcode id=1457 lang=cpp
 *
 * [1457] Pseudo-Palindromic Paths in a Binary Tree
 *
 * https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/description/
 *
 * algorithms
 * Medium (67.95%)
 * Likes:    333
 * Dislikes: 12
 * Total Accepted:    20.9K
 * Total Submissions: 30.7K
 * Testcase Example:  '[2,3,1,3,1,null,1]'
 *
 * Given a binary tree where node values are digits from 1 to 9. A path in the
 * binary tree is said to be pseudo-palindromic if at least one permutation of
 * the node values in the path is a palindrome.
 * 
 * Return the number of pseudo-palindromic paths going from the root node to
 * leaf nodes.
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: root = [2,3,1,3,1,null,1]
 * Output: 2 
 * Explanation: The figure above represents the given binary tree. There are
 * three paths going from the root node to leaf nodes: the red path [2,3,3],
 * the green path [2,1,1], and the path [2,3,1]. Among these paths only red
 * path and green path are pseudo-palindromic paths since the red path [2,3,3]
 * can be rearranged in [3,2,3] (palindrome) and the green path [2,1,1] can be
 * rearranged in [1,2,1] (palindrome).
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: root = [2,1,1,1,3,null,null,null,null,null,1]
 * Output: 1 
 * Explanation: The figure above represents the given binary tree. There are
 * three paths going from the root node to leaf nodes: the green path [2,1,1],
 * the path [2,1,3,1], and the path [2,1]. Among these paths only the green
 * path is pseudo-palindromic since [2,1,1] can be rearranged in [1,2,1]
 * (palindrome).
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: root = [9]
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The given binary tree will have between 1 and 10^5 nodes.
 * Node values are digits from 1 to 9.
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
    int res = 0;
    int pseudoPalindromicPaths (TreeNode* root) {
        res = 0;
        vector<int> mp(10, 0);
        if (root == nullptr) return 0;
        travel(root, mp);
        return res;
    }

    void travel(TreeNode* node, std::vector<int>& mp) {
        if (node->left == nullptr && node->right == nullptr) {
            mp[node->val] ++;
            int odd_cnt = 0;
            for (auto x : mp) {
                if (x & 0x1 != 0) odd_cnt ++;
            }
            if (odd_cnt <= 1) res++;
            mp[node->val] --;
            return;
        }
        else {
            mp[node->val] ++;
        }
        if (node->left)  travel(node->left, mp);
        if (node->right) travel(node->right, mp);

        mp[node->val] --;
    }

    /**
     * @note 炫技 https://zxi.mytechroad.com/blog/uncategorized/leetcode-1457-pseudo-palindromic-paths-in-a-binary-tree/
     */
    /*
    int pseudoPalindromicPaths (TreeNode* node) {
        vector<int> counts(10);
        function<int(TreeNode*)> dfs = [&](TreeNode* node) {
          if (!node) return 0;
          ++counts[node->val];
          int c = 0;
          if (!node->left && !node->right) {
            int odds = 0;
            for (int i = 1; i <= 9; ++i)
              if (counts[i] & 1) ++odds;
            if (odds <= 1) c = 1;
          }
          int l = dfs(node->left);
          int r = dfs(node->right);      
          --counts[node->val];
          return c + l + r;
        };
        return dfs(root);
    }
    int pseudoPalindromicPaths (TreeNode* node, int s = 0) {
        if (!root) return 0;
        s ^= (1 << root->val);
        if (!root->left && !root->right)
          return __builtin_popcount(s) <= 1;
        return pseudoPalindromicPaths(root->left, s) 
             + pseudoPalindromicPaths(root->right, s);
    }

    */

};
// @lc code=end


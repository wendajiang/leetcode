/*
 * @lc app=leetcode id=669 lang=cpp
 *
 * [669] Trim a Binary Search Tree
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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (!root) return NULL;
        if (root->val < low) return trimBST(root->right, low, high);
        if (root->val > high) return trimBST(root->left, low, high);
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }

    /**
     * @brief: loop method
     */
    // TreeNode* trimBST(TreeNode* root, int L, int R) {
    //     if (!root) return NULL;
    //     while (root->val < L || root->val > R) {
    //         root = (root->val < L) ? root->right : root->left;
    //     }
    //     TreeNode *cur = root;
    //     while (cur) {
    //         while (cur->left && cur->left->val < L) {
    //             cur->left = cur->left->right;
    //         }
    //         cur = cur->left;
    //     }
    //     cur = root;
    //     while (cur) {
    //         while (cur->right && cur->right->val > R) {
    //             cur->right = cur->right->left;
    //         }
    //         cur = cur->right;
    //     }
    //     return root;
    // }
};
// @lc code=end


/*
 * [337] House Robber III
 *
 * https://leetcode.com/problems/house-robber-iii
 *
 * Medium (43.17%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[3,2,3,null,3,null,1]'
 *
 *
 * The thief has found himself a new place for his thievery again. There is
 * only one entrance to this area, called the "root." Besides the root, each
 * house has one and only one parent house. After a tour, the smart thief
 * realized that "all houses in this place forms a binary tree". It will
 * automatically contact the police if two directly-linked houses were broken
 * into on the same night.
 *
 *
 *
 * Determine the maximum amount of money the thief can rob tonight without
 * alerting the police.
 *
 *
 * Example 1:
 *
 * ⁠    3
 * ⁠   / \
 * ⁠  2   3
 * ⁠   \   \
 * ⁠    3   1
 *
 * Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
 *
 *
 * Example 2:
 *
 * ⁠    3
 * ⁠   / \
 * ⁠  4   5
 * ⁠ / \   \
 * ⁠1   3   1
 *
 * Maximum amount of money the thief can rob = 4 + 5 = 9.
 *
 *
 * Credits:Special thanks to @dietpepsi for adding this problem and creating
 * all test cases.
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
    // //step I
    // int rob(TreeNode* root) {
    //     if(root == nullptr) return 0;
    //     int val = 0;
    //     if(root->left)
    //         val += rob(root->left->left) + rob(root->left->right);
    //     if(root->right)
    //         val += rob(root->right->left) + rob(root->right->right);
    //     return std::max(val + root->val, rob(root->left) + rob(root->right));
    // }

    // //step II
    // int rob(TreeNode* root){
    //     map<TreeNode*, int> mp;
    //     return robCore(root, mp);
    // }
    // int robCore(TreeNode* node, map<TreeNode*, int>& mp){
    //     if(node == nullptr) return 0;
    //     if(mp.find(node) != mp.end()) return mp[node];
    //     int val = 0;
    //     if(node->left)
    //         val += robCore(node->left->left, mp) + robCore(node->left->right, mp);
    //     if(node->right)
    //         val += robCore(node->right->left, mp) + robCore(node->right->right, mp);
    //     val = std::max(node->val + val, robCore(node->left, mp) + robCore(node->right, mp));
    //     mp[node] = val;
    //     return val;
    // }

    //step III
    int rob(TreeNode* root){
        vector<int> res = robSub(root);
        return max(res[0], res[1]);
    }
    vector<int> robSub(TreeNode* root) {
        if (root == NULL) {
            return vector<int>(2,0);
        }

        vector<int> left = robSub(root->left);
        vector<int> right = robSub(root->right);

        vector<int> res(2,0);
        res[0] = max(left[0], left[1]) + max(right[0], right[1]);
        res[1] = root->val + left[0] + right[0];

        return res;
    }

};

/*
 * [563] Binary Tree Tilt
 *
 * https://leetcode.com/problems/binary-tree-tilt
 *
 * Easy (46.95%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[1,2,3]'
 *
 * Given a binary tree, return the tilt of the whole tree.
 *
 * The tilt of a tree node is defined as the absolute difference between the
 * sum of all left subtree node values and the sum of all right subtree node
 * values. Null node has tilt 0.
 *
 * The tilt of the whole tree is defined as the sum of all nodes' tilt.
 *
 * Example:
 *
 * Input:
 * ⁠        1
 * ⁠      /   \
 * ⁠     2     3
 * Output: 1
 * Explanation:
 * Tilt of node 2 : 0
 * Tilt of node 3 : 0
 * Tilt of node 1 : |2-3| = 1
 * Tilt of binary tree : 0 + 0 + 1 = 1
 *
 *
 *
 * Note:
 *
 * The sum of node values in any subtree won't exceed the range of 32-bit
 * integer.
 * All the tilt values won't exceed the range of 32-bit integer.
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
    int findTilt(TreeNode* root){
        int res = 0;
        traversal(root, res);
        return res;
    }

    int traversal(TreeNode* node, int& res){
        if(!node) return 0;
        int leftSum = traversal(node->left, res), rightSum = traversal(node->right, res);
        res += std::abs(leftSum - rightSum);
        return leftSum + rightSum + node->val;
    }

    // int findTilt(TreeNode* root) {
    //     if(root == nullptr) return 0;
    //     stack<TreeNode*> st;
    //     TreeNode* cur = root;
    //     int res = 0;
    //     while(cur || !st.empty()){
    //         if(cur){
    //             st.push(cur);
    //             cur = cur->left;
    //         }else{
    //             cur = st.top();
    //             st.pop();
    //             res += getTile(cur);
    //             cur = cur->right;
    //         }
    //     }
    //     return res;
    // }
    // int getTile(TreeNode* node){
    //     if(node){
    //         return std::abs(subTreeSum(node->left) - subTreeSum(node->right));
    //     }else{
    //         return 0;
    //     }
    // }
    // int subTreeSum(TreeNode* node){
    //     if(node == nullptr) return 0;
    //     return node->val + subTreeSum(node->left) + subTreeSum(node->right);
    // }
};

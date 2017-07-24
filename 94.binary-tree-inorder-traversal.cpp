/*
 * [94] Binary Tree Inorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-inorder-traversal
 *
 * Medium (46.13%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the inorder traversal of its nodes' values.
 *
 *
 * For example:
 * Given binary tree [1,null,2,3],
 *
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 *
 *
 *
 * return [1,3,2].
 *
 *
 * Note: Recursive solution is trivial, could you do it iteratively?
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
    //Morris Traversal
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode *cur = root, *pre = NULL;
        vector<int> res;
        while(cur){
            if(cur->left){
                pre = cur->left;
                while((pre->right) && (pre->right != cur))
                    pre = pre->right;
                if(!(pre->right)){
                    pre->right = cur;
                    cur = cur->left;
                }else {
                    pre->right = NULL;
                    res.push_back(cur->val);
                    cur = cur->right;
                }
            }else{
                res.push_back(cur->val);
                cur = cur->right;
            }
        }
        return res;
    }

    // vector<int> inorderTraversal(TreeNode* root) {
    //     vector<int> nodes;
    //     stack<TreeNode*> toVisit;
    //     TreeNode* curNode = root;
    //     while (curNode || !toVisit.empty()) {
    //         if (curNode) {
    //             toVisit.push(curNode);
    //             curNode = curNode -> left;
    //         }
    //         else {
    //             curNode = toVisit.top();
    //             toVisit.pop();
    //             nodes.push_back(curNode -> val);
    //             curNode = curNode -> right;
    //         }
    //     }
    //     return nodes;
    //
    //     ////recurse methoed
    //     // if(root == NULL) return {}:
    //     // vector<int> res;
    //     // iTraversal(root, res);
    //     // return res;
    // }
    // void iTraversal(TreeNode* node, vector<int>& res){
    //     // if(node == NULL) return;
    //     if(node->left) iTraversal(node->left, res);
    //     res.push_back(node->val);
    //     if(node->right) iTraversal(node->right, res);
    // }
};

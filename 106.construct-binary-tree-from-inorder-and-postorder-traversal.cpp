/*
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal
 *
 * Medium (31.90%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[]\n[]'
 *
 * Given inorder and postorder traversal of a tree, construct the binary tree.
 *
 * Note:
 * You may assume that duplicates do not exist in the tree.
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() != postorder.size())
            return NULL;
        return buildTreeCore(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
    TreeNode* buildTreeCore(vector<int>& inorder, int startin, int endin, vector<int>& postorder, int startpost, int endpost){
        if(startpost > endpost) return NULL;
        int root = postorder[endpost];
        int i = endin;
        for(; i >= startin; i--){
            if(root == inorder[i])
                break;
        }
        TreeNode* node = new TreeNode(root);
        node->left = buildTreeCore(inorder, startin, i - 1, postorder, startpost, startpost + i - startin - 1);
        node->right = buildTreeCore(inorder, i + 1, endin, postorder, endpost - (endin - i), endpost - 1);
        return node;
    }
};

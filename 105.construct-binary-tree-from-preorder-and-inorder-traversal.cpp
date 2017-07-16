/*
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal
 *
 * Medium (31.96%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[]\n[]'
 *
 * Given preorder and inorder traversal of a tree, construct the binary tree.
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeCore(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
    TreeNode* buildTreeCore(vector<int>& preorder, int startpre, int endpre, vector<int>& inorder, int startin, int endin){
        if(startpre > endpre) return NULL;
        int root = preorder[startpre];
        int i = startin;
        for(; i <= endin; i++){
            if(inorder[i] == root)
                break;
        }
        TreeNode *node = new TreeNode(root);
        node->left = buildTreeCore(preorder, startpre + 1, startpre + i - startin, inorder, startin, i - 1);
        node->right = buildTreeCore(preorder, startpre + i - startin + 1, endpre, inorder, i + 1, endin);
        return node;
    }
};

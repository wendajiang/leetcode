/*
 * [257] Binary Tree Paths
 *
 * https://leetcode.com/problems/binary-tree-paths
 *
 * Easy (37.95%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[1,2,3,null,5]'
 *
 *
 * Given a binary tree, return all root-to-leaf paths.
 *
 *
 * For example, given the following binary tree:
 *
 *
 *
 * ⁠  1
 * ⁠/   \
 * 2     3
 * ⁠\
 * ⁠ 5
 *
 *
 *
 * All root-to-leaf paths are:
 * ["1->2->5", "1->3"]
 *
 *
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and
 * creating all test cases.
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string s;
        findPath(root, res, s);
        return res;
    }
    void findPath(TreeNode* root, vector<string>& res, string s){
        if(root == nullptr) return;
        if(root && (root->left == nullptr && root->right == nullptr)){
            s += to_string(root->val);
            res.push_back(s);
        }
        if(root && (root->left || root->right)) {

            findPath(root->left, res, s + to_string(root->val) + "->");
            findPath(root->right, res, s + to_string(root->val) + "->");
        }


    }
};

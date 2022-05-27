/*
 * [501] Find Mode in Binary Search Tree
 *
 * https://leetcode.com/problems/find-mode-in-binary-search-tree
 *
 * Easy (38.04%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[1,null,2,2]'
 *
 * Given a binary search tree (BST) with duplicates, find all the mode(s) (the
 * most frequently occurred element) in the given BST.
 *
 *
 * Assume a BST is defined as follows:
 *
 * The left subtree of a node contains only nodes with keys less than or equal
 * to the node's key.
 * The right subtree of a node contains only nodes with keys greater than or
 * equal to the node's key.
 * Both the left and right subtrees must also be binary search trees.
 *
 *
 *
 *
 * For example:
 * Given BST [1,null,2,2],
 *
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  2
 *
 *
 *
 * return [2].
 *
 *
 * Note:
 * If a tree has more than one mode, you can return them in any order.
 *
 *
 * Follow up:
 * Could you do that without using any extra space? (Assume that the implicit
 * stack space incurred due to recursion does not count).
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
    vector<int> findMode(TreeNode* root) {
        if(!root) return {};
        stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* pre = nullptr;
        int maxLen = INT_MIN;
        vector<int> res;
        int count = 1;
        while(cur || !st.empty()){
            if(cur){
                st.push(cur);
                cur = cur->left;
            }else{
                cur = st.top();
                st.pop();
                if(pre && pre->val == cur->val){
                    count++;
                }else if(pre && pre->val != cur->val){
                    count = 1;
                }
                if(maxLen == count){
                    res.push_back(cur->val);
                }else if(maxLen < count){
                    maxLen = count;
                    res.clear();
                    res.push_back(cur->val);
                }
                pre = cur;
                cur = cur->right;
            }
        }
        
        return res;
    }
};

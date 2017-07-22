/*
 * [230] Kth Smallest Element in a BST
 *
 * https://leetcode.com/problems/kth-smallest-element-in-a-bst
 *
 * Medium (43.57%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[1]\n1'
 *
 * Given a binary search tree, write a function kthSmallest to find the kth
 * smallest element in it.
 *
 * Note:
 * You may assume k is always valid, 1 ? k ? BST's total elements.
 *
 * Follow up:
 * What if the BST is modified (insert/delete operations) often and you need to
 * find the kth smallest frequently? How would you optimize the kthSmallest
 * routine?
 *
 * Credits:Special thanks to @ts for adding this problem and creating all test
 * cases.
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
    int kthSmallest(TreeNode* root, int k) {
        int res = 0;
        stack<TreeNode*> st;
        st.push(root);
        TreeNode* node = st.top();
        while(node || !st.empty()){
            if(node){
                st.push(node);
                node = node->left;
            }else{
                node = st.top();
                st.pop();
                res = node->val;
                k--;
                if(k == 0)
                    break;
                node = node->right;
            }
        }
        return res;
    }
};

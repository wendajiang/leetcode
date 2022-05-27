/*
 * [404] Sum of Left Leaves
 *
 * https://leetcode.com/problems/sum-of-left-leaves
 *
 * Easy (46.92%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Find the sum of all left leaves in a given binary tree.
 *
 * Example:
 *
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 *
 * There are two left leaves in the binary tree, with values 9 and 15
 * respectively. Return 24.
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
    int sumOfLeftLeaves(TreeNode* root) {
        TreeNode* cur = root;
        // TreeNode* pre = nullptr;
        stack<TreeNode*> st;
        int sum = 0;
        while(cur || !st.empty()){
            if(cur){
                // pre = cur;
                st.push(cur);
                cur = cur->left;
            }else{
                cur = st.top();
                st.pop();
                if(!cur->left && !cur->right && st.size() > 0 && st.top()->left == cur){
                    sum += cur->val;
                }
                cur = cur->right;
            }
        }
        return sum;
    }
};

/*
 * [114] Flatten Binary Tree to Linked List
 *
 * https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/
 *
 * algorithms
 * Medium (36.39%)
 * Total Accepted:    162.7K
 * Total Submissions: 445.7K
 * Testcase Example:  '[]'
 *
 *
 * Given a binary tree, flatten it to a linked list in-place.
 *
 *
 *
 * For example,
 * Given
 *
 * ⁠        1
 * ⁠       / \
 * ⁠      2   5
 * ⁠     / \   \
 * ⁠    3   4   6
 *
 *
 *
 * The flattened tree should look like:
 *
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠     \
 * ⁠      3
 * ⁠       \
 * ⁠        4
 * ⁠         \
 * ⁠          5
 * ⁠           \
 * ⁠            6
 *
 *
 * click to show hints.
 *
 * Hints:
 * If you notice carefully in the flattened tree, each node's right child
 * points to the next node of a pre-order traversal.
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

    //先序遍历的循环写法
    void flatten(TreeNode* root) {
        if(root == NULL) return ;
        stack<TreeNode*> st;
        st.push(root);
        TreeNode *p, *pre = NULL;
        while(!st.empty()){
            p = st.top();
            st.pop();
            if(p->right) st.push(p->right);
            if(p->left) st.push(p->left);

            p->left = NULL;
            if(pre != NULL)
                pre->right = p;
            pre = p;
        }
    }
};

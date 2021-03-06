/*
 * [100] Same Tree
 *
 * https://leetcode.com/problems/same-tree
 *
 * Easy (46.28%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[]\n[]'
 *
 *
 * Given two binary trees, write a function to check if they are equal or
 * not.
 *
 *
 * Two binary trees are considered equal if they are structurally identical and
 * the nodes have the same value.
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && q)
            return false;
        else if(!q && p)
            return false;
        else if(!p && !q)
            return true;
        else if(p->val != q->val)
            return false;
        else
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);

/*
if (p == NULL || q == NULL) return (p == q);
    return (p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
}
*/
    }
};

/*
 * [235] Lowest Common Ancestor of a Binary Search Tree
 *
 * https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree
 *
 * Easy (38.88%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[2,1]\nnode with value 2\nnode with value 1'
 *
 *
 * Given a binary search tree (BST), find the lowest common ancestor (LCA) of
 * two given nodes in the BST.
 *
 *
 *
 * According to the definition of LCA on Wikipedia: “The lowest common ancestor
 * is defined between two nodes v and w as the lowest node in T that has both v
 * and w as descendants (where we allow a node to be a descendant of
 * itself).”
 *
 *
 *
 * ⁠       _______6______
 * ⁠      /              \
 * ⁠   ___2__          ___8__
 * ⁠  /      \        /      \
 * ⁠  0      _4       7       9
 * ⁠        /  \
 * ⁠        3   5
 *
 *
 *
 * For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. Another
 * example is LCA of nodes 2 and 4 is 2, since a node can be a descendant of
 * itself according to the LCA definition.
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if(aIsRootOfB(p, q)){
            TreeNode* cur = root;
            TreeNode* pre;
            while(cur != p){
                pre = cur;
                if(cur->val < p->val){
                    cur = cur->right;
                }else{
                    cur = cur->left;
                }
            }
            return cur;
        }else if(aIsRootOfB(q, p)){
            TreeNode* cur = root;
            TreeNode* pre;
            while(cur != q){
                pre = cur;
                if(cur->val < q->val){
                    cur = cur ->right;
                }else{
                    cur = cur->left;
                }
            }
            return cur;
        }else{
            if((root->val > p->val) && (root->val > q->val)){
                return lowestCommonAncestor(root->left, p, q);
            }else if((root->val < p->val) && (root->val < q->val)){
                return lowestCommonAncestor(root->right, p, q);
            }else if(((root->val < p->val) && (root->val > q->val)) || ((root->val > p->val) && (root->val < q->val))){
                return root;
            }
        }
        return nullptr;
    }

    bool aIsRootOfB(TreeNode* a, TreeNode* b){
        if((!a && b) || (!b && a) || (!a && !b)) return false;
        if(a == b) return true;
        return aIsRootOfB(a->left,  b) || aIsRootOfB(a->right, b);
    }
};

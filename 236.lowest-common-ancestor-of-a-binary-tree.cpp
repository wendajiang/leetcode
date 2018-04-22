/*
 * [236] Lowest Common Ancestor of a Binary Tree
 *
 * https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree
 *
 * Medium (29.68%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[1,2]\nnode with value 1\nnode with value 2'
 *
 *
 * Given a binary tree, find the lowest common ancestor (LCA) of two given
 * nodes in the tree.
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
 * ⁠       _______3______
 * ⁠      /              \
 * ⁠   ___5__          ___1__
 * ⁠  /      \        /      \
 * ⁠  6      _2       0       8
 * ⁠        /  \
 * ⁠        7   4
 *
 *
 *
 * For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. Another
 * example is LCA of nodes 5 and 4 is 5, since a node can be a descendant of
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == p || root == q || root == NULL) return root;
        TreeNode* parent1 = lowestCommonAncestor(root->left, p, q);
        TreeNode* parent2 = lowestCommonAncestor(root->right, p, q);
        if(parent1 && parent2){
            return root;
        }else{
            return parent1 ? parent1 : parent2;
        }
    }


    // TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //     if(aIsRootOfB(p, q)){
    //         return p;
    //     }else if(aIsRootOfB(q, p)){
    //         return q;
    //     }else{
    //         vector<TreeNode*> nodes, res;
    //         findPath(root, p, nodes, res);
    //         for(int i = res.size() - 1; i >=0; i--){
    //             if(aIsRootOfB(res[i], q)){
    //                 return res[i];
    //             }
    //         }
    //     }
    //     return nullptr;
    // }
    //
    // bool aIsRootOfB(TreeNode* a, TreeNode* b){
    //     if((!a && b) || (!b && a) || (!a && !b)) return false;
    //     if(a == b) return true;
    //     return aIsRootOfB(a->left,  b) || aIsRootOfB(a->right, b);
    // }
    //
    // void findPath(TreeNode* a, TreeNode* b, vector<TreeNode*> path, vector<TreeNode*>& res){
    //     path.push_back(a);
    //     if(a == b){
    //         res = path;
    //         return;
    //     }else if(!a){
    //         path.pop_back();// pop the nullptr
    //         path.pop_back();// pop the leaf
    //         return;
    //     }
    //     findPath(a->left, b, path, res);
    //     findPath(a->right, b, path, res);
    //
    // }
};

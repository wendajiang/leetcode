/*
 * [99] Recover Binary Search Tree
 *
 * https://leetcode.com/problems/recover-binary-search-tree
 *
 * Hard (29.71%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[0,1]'
 *
 *
 * Two elements of a binary search tree (BST) are swapped by mistake.
 *
 * Recover the tree without changing its structure.
 *
 *
 * Note:
 * A solution using O(n) space is pretty straight forward. Could you devise a
 * constant space solution?
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

/*
inorder 遍历存在两种（递归和迭代），但都是O(n)space，O(1)的解法
为
Morris traversal 关键点
*/

class Solution {
public:
    // // 递归的中序遍历解法
    // void recoverTree(TreeNode* root) {
    //     TreeNode* pre = nullptr;
    //     TreeNode* first = nullptr;
    //     TreeNode* second = nullptr;
    //     inOrder(root, first, second, pre);
    //     int tmp = first->val;
    //     first->val = second->val;
    //     second->val = tmp;
    // }
    // void inOrder(TreeNode* root, TreeNode*& first, TreeNode*& second, TreeNode*& pre){
    //     if(!root) return;
    //     inOrder(root->left, first, second, pre);
    //     if(pre != nullptr && pre->val >= root->val){
    //         //incorrect smaller node is always found as prev node
    //         if(first == nullptr) first = pre;
    //         //incorrect larger node is always found as curr(root) node
    //         second = root;
    //     }
    //     pre = root;
    //     inOrder(root->right, first, second, pre);
    // }

    // //迭代的中序遍历解法
    // void recoverTree(TreeNode* root){
    //     TreeNode* pre = nullptr;
    //     TreeNode* first = nullptr;
    //     TreeNode* second = nullptr;
    //     stack<TreeNode*> st;
    //     TreeNode* cur = root;
    //     while(cur || !st.empty()){
    //         while(cur){
    //             st.push(cur);
    //             cur = cur->left;
    //         }
    //         cur = st.top();
    //         st.pop();
    //         if(pre && pre->val >= cur->val){
    //             if(!first) first = pre;
    //             second = cur;
    //         }
    //         pre = cur;
    //         cur = cur->right;
    //     }
    //     int tmp = first->val;
    //     first->val = second->val;
    //     second->val = tmp;
    // }

    //Morris Traversal solution
    void recoverTree(TreeNode* root){
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;
        TreeNode* preNode = nullptr;

        TreeNode* pre = nullptr;
        TreeNode* cur = root;

        while(cur){
            if(cur->left){
                pre = cur->left;
                while((pre->right) && (pre->right != cur))
                    pre = pre->right;
                if(!(pre->right)){
                    pre->right = cur;
                    cur = cur->left;
                }else {
                    if(preNode && preNode->val >= cur->val){
                        if(!first) first = preNode;
                        second = cur;
                    }
                    preNode = cur;
                    pre->right = NULL;  //拆开链接后继的右节点域
                    cur = cur->right;
                }
            }else{
                if(preNode && preNode->val >= cur->val){
                    if(!first) first = preNode;
                    second = cur;
                }
                preNode = cur;
                cur = cur->right;
            }
        }

        int tmp = first->val;
        first->val = second->val;
        second->val = tmp;
    }

};

++++++++++++++++++++++++++++++++/*
 * @lc app=leetcode id=450 lang=cpp
 *
 * [450] Delete Node in a BST
 *
 * https://leetcode.com/problems/delete-node-in-a-bst/description/
 *
 * algorithms
 * Medium (45.15%)
 * Likes:    3528
 * Dislikes: 116
 * Total Accepted:    193K
 * Total Submissions: 415.8K
 * Testcase Example:  '[5,3,6,2,4,null,7]\n3'
 *
 * Given a root node reference of a BST and a key, delete the node with the
 * given key in the BST. Return the root node reference (possibly updated) of
 * the BST.
 *
 * Basically, the deletion can be divided into two stages:
 *
 *
 * Search for a node to remove.
 * If the node is found, delete the node.
 *
 *
 * Follow up: Can you solve it with time complexity O(height of tree)?
 *
 *
 * Example 1:
 *
 *
 * Input: root = [5,3,6,2,4,null,7], key = 3
 * Output: [5,4,6,2,null,null,7]
 * Explanation: Given key to delete is 3. So we find the node with value 3 and
 * delete it.
 * One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
 * Please notice that another valid answer is [5,2,6,null,4,null,7] and it's
 * also accepted.
 *
 *
 *
 * Example 2:
 *
 *
 * Input: root = [5,3,6,2,4,null,7], key = 0
 * Output: [5,3,6,2,4,null,7]
 * Explanation: The tree does not contain a node with value = 0.
 *
 *
 * Example 3:
 *
 *
 * Input: root = [], key = 0
 * Output: []
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [0, 10^4].
 * -10^5 <= Node.val <= 10^5
 * Each node has a unique value.
 * root is a valid binary search tree.
 * -10^5 <= key <= 10^5
 *
 *
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (nullptr == root) return root;
        TreeNode *find = nullptr;
        TreeNode *p_find = nullptr;
        findNode(nullptr, root, key, find, p_find);
        if (find == nullptr) return root;
        else {
            if (find->left == nullptr) {
                transplant(root, find, p_find, find->right, find);
            } else if (find->right == nullptr) {
                transplant(root, find, p_find, find->left, find);
            } else {
                TreeNode *f = nullptr;
                TreeNode *p_f = nullptr;
                findMini(find, find->right, f, p_f);
                if (p_f != find) {
                    transplant(root, f, p_f, f->right, f);
                    f->right = find->right;
                }
                transplant(root, find, p_find, f, p_f);
                f->left = find->left;
            }
        }
        return root;
    }

private:
    void findNode(TreeNode *p_node, TreeNode *node, int key, TreeNode *find, TreeNode* p_find) {
        if (node->val == key) {
            p_find = p_node;
            find = node;
            return;
        }
        else if (node->val > key && node->left) findNode(node, node->left, key, find, p_find);
        else if (node->val < key && node->right) findNode(node, node->right, key, find, p_find);
    }

    void transplant(TreeNode *root, TreeNode *u, TreeNode *u_p, TreeNode *v, TreeNode *v_p) {
        if (u_p == nullptr) root = v;
        else if (u == u_p->left) u_p->left = v;
        else u_p->right = v;

        if (v == nullptr) v_p = u_p;

    }
    void findMini(TreeNode *p_node, TreeNode *node, TreeNode *f, TreeNode *p_f) {
        if (node->left == nullptr) {
            f = node;
            p_f = p_node;
            return;
        }
        findMini(node, node->left, f, p_f);
    }
};
// @lc code=end

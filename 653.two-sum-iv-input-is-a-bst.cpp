/*
 * [653] Two Sum IV - Input is a BST
 *
 * https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/
 *
 * algorithms
 * Easy (49.98%)
 * Total Accepted:    34.7K
 * Total Submissions: 69.4K
 * Testcase Example:  '[5,3,6,2,4,null,7]\n9'
 *
 * Given a Binary Search Tree and a target number, return true if there exist
 * two elements in the BST such that their sum is equal to the given target.
 * 
 * Example 1:
 * 
 * Input: 
 * ⁠   5
 * ⁠  / \
 * ⁠ 3   6
 * ⁠/ \   \
 * 2   4   7
 * 
 * Target = 9
 * 
 * Output: True
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: 
 * ⁠   5
 * ⁠  / \
 * ⁠ 3   6
 * ⁠/ \   \
 * 2   4   7
 * 
 * Target = 28
 * 
 * Output: False
 * 
 * 
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
    vector<int> tree;
    bool findTarget(TreeNode* root, int k) {
        inorderWalk(root);
        int len = tree.size();
        map<int, int> mp;
        for(int i = 0; i < len; i++){
            mp[tree[i]] = i;
        }
        bool ans = false;
        for(int i = 0; i < len; i++){
            int tt = k - tree[i];
            if(mp.find(tt) != mp.end() && i != mp[tt]){
                ans = true;
                break;
            }
        }
        return ans;
    }

    void inorderWalk(TreeNode* node){
        if(node != nullptr){
            inorderWalk(node->left);
            tree.push_back(node->val);
            inorderWalk(node->right);
        }
    }

    
};

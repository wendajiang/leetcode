/*
 * [117] Populating Next Right Pointers in Each Node II
 *
 * https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/description/
 *
 * algorithms
 * Medium (33.93%)
 * Total Accepted:    129.7K
 * Total Submissions: 382.5K
 * Testcase Example:  '{}'
 *
 * Given a binary tree
 *
 *
 * struct TreeLinkNode {
 * ⁠ TreeLinkNode *left;
 * ⁠ TreeLinkNode *right;
 * ⁠ TreeLinkNode *next;
 * }
 *
 *
 * Populate each next pointer to point to its next right node. If there is no
 * next right node, the next pointer should be set to NULL.
 *
 * Initially, all next pointers are set to NULL.
 *
 * Note:
 *
 *
 * You may only use constant extra space.
 * Recursive approach is fine, implicit stack space does not count as extra
 * space for this problem.
 *
 *
 * Example:
 *
 * Given the following binary tree,
 *
 *
 * ⁠    1
 * ⁠  /  \
 * ⁠ 2    3
 * ⁠/ \    \
 * 4   5    7
 *
 *
 * After calling your function, the tree should look like:
 *
 *
 * ⁠    1 -> NULL
 * ⁠  /  \
 * ⁠ 2 -> 3 -> NULL
 * ⁠/ \    \
 * 4-> 5 -> 7 -> NULL
 *
 *
 */
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root) return;
        vector<TreeLinkNode*> Q;
        int l = 0, r = 1;
        Q.push_back(root);
        while(l < r){
            int end = r;
            for(int i = l; i < end; i++){
                if(i == end - 1){
                    if(Q[i]->left) Q.push_back(Q[i]->left);
                    if(Q[i]->right) Q.push_back(Q[i]->right);
                    Q[i]->next = NULL;
                }else{
                    if(Q[i]->left) Q.push_back(Q[i]->left);
                    if(Q[i]->right) Q.push_back(Q[i]->right);
                    Q[i]->next = Q[i + 1];
                }
            }
            l = end;
            r = Q.size();
        }
    }
};

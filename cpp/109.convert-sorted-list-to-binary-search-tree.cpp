/*
 * [109] Convert Sorted List to Binary Search Tree
 *
 * https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree
 *
 * Medium (33.83%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[]'
 *
 * Given a singly linked list where elements are sorted in ascending order,
 * convert it to a height balanced BST.
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
树的问题基本出发点就是三种遍历
上一题108，是数组，因为BST的中序遍历就是升序的，而且每个元素可以通过下标访问到，所以可以从中间到两边，对树的重建就是从上到下

单链表每次要从头遍历，所以不能从上到下建树（访问链表从中间到两边），要反向中序遍历的过程建树，所以要知道链表的长度
*/
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int len = 0;
        ListNode* index = head;
        while(index){
            len++;
            index = index->next;
        }
        return buildTree(head, 0, len - 1);
    }

    TreeNode* buildTree(ListNode*& cur, int start, int end){
        if(start > end) return nullptr;
        int mid = (start + end) / 2;
        TreeNode* leftChild = buildTree(cur, start, mid - 1);
        TreeNode* parent = new TreeNode(cur->val);
        parent->left = leftChild;
        cur = cur->next;
        parent->right = buildTree(cur, mid + 1, end);
        return parent;
    }
};

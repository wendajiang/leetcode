/*
 * [203] Remove Linked List Elements
 *
 * https://leetcode.com/problems/remove-linked-list-elements
 *
 * Easy (32.13%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[1,2,6,3,4,5,6]\n6'
 *
 * Remove all elements from a linked list of integers that have value val.
 *
 * Example
 * Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6,  val = 6
 * Return: 1 --> 2 --> 3 --> 4 --> 5
 *
 *
 * Credits:Special thanks to @mithmatt for adding this problem and creating all
 * test cases.
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL)
            return head;
        ListNode *cur = head;
        ListNode *pre = NULL;
        while(cur){
            if(pre && cur->val == val){
                pre->next = cur->next;
                cur = cur->next;
                continue;
            }else if(!pre && cur->val == val){
                cur = cur->next;
                head = cur;
                continue;
            }
            pre = cur;
            cur = cur->next;

        }
        return head;
    }
};

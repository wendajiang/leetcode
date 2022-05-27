/*
 * [206] Reverse Linked List
 *
 * https://leetcode.com/problems/reverse-linked-list
 *
 * Easy (45.10%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[]'
 *
 * Reverse a singly linked list.
 *
 * click to show more hints.
 *
 * Hint:
 * A linked list can be reversed either iteratively or recursively. Could you
 * implement both?
 *
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
    ListNode* reverseList(ListNode* head) {

        // if(head == NULL || head->next == NULL){
        //     return head;
        // }
        // ListNode* cur = NULL;
        // ListNode* pNext = NULL;
        // cur = head;
        // pNext = cur->next;
        // while(pNext != NULL){
        //     cur->next = pNext->next;
        //     pNext->next = head;
        //     head = pNext;
        //     pNext = cur->next;
        //
        // }
        // return head;

        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode *preHead = new ListNode(INT_MIN);
        preHead->next = head;
        ListNode *pre = preHead, *cur = preHead->next, *curNext = cur->next;
        while(curNext){
            cur->next = curNext->next;
            curNext->next = preHead->next;
            preHead->next = curNext;
            curNext = cur->next;
        }
        ListNode *tmpHead = preHead->next;
        delete preHead;
        return tmpHead;

    }
};

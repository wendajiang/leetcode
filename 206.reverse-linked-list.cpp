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
<<<<<<< HEAD:206.reverse-linked-list.cpp
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* cur = NULL;
        ListNode* pNext = NULL;
        cur = head;
        pNext = cur->next;
        while(pNext != NULL){
            cur->next = pNext->next;
            pNext->next = head;
            head = pNext;
            pNext = cur->next;
        
        }
        return head;
=======

>>>>>>> b2b8a96fd623e83f9b08a5da7d8c044305d74399:206.reverse-linked-list.notac.cpp
    }
};
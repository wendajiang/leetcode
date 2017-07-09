/*
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists
 *
 * Easy (38.94%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[]\n[]'
 *
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        ListNode* result = new ListNode((l1->val < l2->val) ? l1->val : l2->val);
        if(l1->val < l2->val)
            l1 = l1->next;
        else
            l2 = l2->next;
        ListNode* head = result;
        while(l1 != NULL && l2 != NULL){
            if(l1->val < l2->val){
                result->next = new ListNode(l1->val);
                result = result->next;
                l1 = l1->next;
            }else {
                result->next = new ListNode(l2->val);
                result = result->next;
                l2 = l2->next;
            }
        }
        if(l1 == NULL){
            while(l2 != NULL){
                result->next = new ListNode(l2->val);
                result = result->next;
                l2 = l2->next;
            }
        }else if(l2 == NULL){
            while(l1 != NULL){
                result->next = new ListNode(l1->val);
                result = result->next;
                l1 = l1->next;
            }
        }
        return head;
    }
};

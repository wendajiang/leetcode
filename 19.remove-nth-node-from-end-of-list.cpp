/*
 * [19] Remove Nth Node From End of List
 *
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list
 *
 * Medium (33.19%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '[1]\n1'
 *
 * Given a linked list, remove the nth node from the end of list and return its
 * head.
 * 
 * 
 * For example,
 * 
 * 
 * ⁠  Given linked list: 1->2->3->4->5, and n = 2.
 * 
 * ⁠  After removing the second node from the end, the linked list becomes
 * 1->2->3->5.
 * 
 * 
 * 
 * Note:
 * Given n will always be valid.
 * Try to do this in one pass.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* index = head;
        int length = 0;
        while(index != NULL){
            length++;
            index = index->next;
        }
        if(n > length)
            return head;
        ListNode* indexSlow = head;
        index = head;
        for(int i = 0; i < n; i++){
            index = index->next;
        }
        ListNode* preSlow = indexSlow;
        while(index != NULL){
            index = index->next;
            preSlow = indexSlow;
            indexSlow = indexSlow->next;
        }
        if(indexSlow == head){
            head = head->next;
            return head;
        }
        preSlow->next = indexSlow->next;
        return head;
        
    }
};

/*
 * [83] Remove Duplicates from Sorted List
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list
 *
 * Easy (39.68%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[]'
 *
 *
 * Given a sorted linked list, delete all duplicates such that each element
 * appear only once.
 *
 *
 * For example,
 * Given 1->1->2, return 1->2.
 * Given 1->1->2->3->3, return 1->2->3.
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* index = head;
        while(index != NULL){
            while(index->next != NULL && index->val == index->next->val){
                index->next = index->next->next;
            }
            index = index->next;
        }
        return head;
    }
};

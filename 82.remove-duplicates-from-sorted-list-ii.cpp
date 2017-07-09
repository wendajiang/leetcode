/*
 * [82] Remove Duplicates from Sorted List II
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii
 *
 * Medium (29.30%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[]'
 *
 *
 * Given a sorted linked list, delete all nodes that have duplicate numbers,
 * leaving only distinct numbers from the original list.
 *
 *
 * For example,
 * Given 1->2->3->3->4->4->5, return 1->2->5.
 * Given 1->1->1->2->3, return 2->3.
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
        if((head == NULL) || (head->next == NULL))
            return head;
        ListNode *pre = NULL, *index = head;
        // bool isDup = false;
        while(index){
            if(index->next && index->val == index->next->val){
                index = index->next;
                continue;
            }
            if(pre == NULL && index != head){
                head = index->next;
                index = head;
                continue;
            }else if(pre == NULL && index == head){
                pre = index;
                index = index->next;
                continue;
            }
            if(pre->next != index){
                pre->next = index->next;
                index = index->next;
            }else{
                pre = index;
                index = index->next;
            }

        }

        if(pre && pre->next != index){
            pre->next = index->next;
        }
        return head;
    }
};

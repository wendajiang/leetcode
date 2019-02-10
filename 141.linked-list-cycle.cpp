/*
 * [141] Linked List Cycle
 *
 * https://leetcode.com/problems/linked-list-cycle
 *
 * Easy (35.39%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[]\nno cycle'
 *
 *
 * Given a linked list, determine if it has a cycle in it.
 *
 *
 *
 * Follow up:
 * Can you solve it without using extra space?
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
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return false;
        bool res = false;
        ListNode *slow = head, *fast = head;
        while(fast && slow){
            slow = slow->next;
            if(fast->next){
                fast = fast->next->next;
            }else{
                break;
            }
            if(fast == slow){
                res = true;
                break;
            }
        }
        return res;
    }
};

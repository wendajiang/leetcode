/*
 * [142] Linked List Cycle II
 *
 * https://leetcode.com/problems/linked-list-cycle-ii
 *
 * Medium (31.02%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[]\nno cycle'
 *
 *
 * Given a linked list, return the node where the cycle begins. If there is no
 * cycle, return null.
 *
 *
 *
 * Note: Do not modify the linked list.
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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return NULL;
        ListNode *slow = head, *fast = head;
        bool isCycle = false;
        while(slow && fast){
            slow = slow->next;
            if(fast->next){
                fast = fast->next->next;
            }else{
                break;
            }
            if(slow == fast){
                isCycle = true;
                break;
            }
        }
        if(isCycle){
            slow = head;
            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }else{
            return NULL;
        }
    }
};

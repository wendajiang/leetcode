/*
 * [92] Reverse Linked List II
 *
 * https://leetcode.com/problems/reverse-linked-list-ii
 *
 * Medium (30.51%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[5]\n1\n1'
 *
 *
 * Reverse a linked list from position m to n. Do it in-place and in
 * one-pass.
 *
 *
 *
 * For example:
 * Given 1->2->3->4->5->NULL, m = 2 and n = 4,
 *
 *
 * return 1->4->3->2->5->NULL.
 *
 *
 * Note:
 * Given m, n satisfy the following condition:
 * 1 ? m ? n ? length of list.
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m > n || m == n) return head;
        ListNode *preHead = new ListNode(INT_MIN);
        preHead->next = head;
        ListNode *fast = head, *slow = head;
        //ListNode *last = NULL;
        ListNode *cur = head, *preSlow = preHead, *pre = preHead;
        int i = 1;
        while(slow && i < m){
            preSlow = slow;
            slow = slow->next;
            i++;
        }
        if(!slow){
            return head;
        }

        fast = slow;
        while(fast && i < n){
            cur = fast;
            fast = fast->next;
            i++;
        }
        if(!fast){
            fast = cur;
        }
        cur = slow;
        pre = preSlow;
        ListNode *tmpHeadNext = pre->next;
        while(cur->next && pre->next != fast){
            tmpHeadNext = pre->next;
            pre->next = cur->next;
            cur->next = cur->next->next;
            pre->next->next = tmpHeadNext;
        }
        ListNode* tmp = preHead->next;
        delete preHead;
        return tmp;


    }
};

/*
 * [61] Rotate List
 *
 * https://leetcode.com/problems/rotate-list
 *
 * algorithms
 * Medium (24.34%)
 * Total Accepted:    113.7K
 * Total Submissions: 467.2K
 * Testcase Example:  '[]\n0'
 *
 * Given a list, rotate the list to the right by k places, where k is
 * non-negative.
 *
 * For example:
 * Given 1->2->3->4->5->NULL and k = 2,
 * return 4->5->1->2->3->NULL.
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || k == 0) return head;
        ListNode* cur = head;
        int len = 0;
        ListNode* last = cur;
        while(cur){
            len++;
            last = cur;
            cur = cur->next;
        }
        cur = head;
        ListNode* pre = cur;
        k = k % len;
        if(k == 0) return head;
        for(int i = 0; i < len - k; i ++){
            pre = cur;
            cur = cur->next;
        }
        pre->next = nullptr;
        last->next = head;
        return cur;
    }
};

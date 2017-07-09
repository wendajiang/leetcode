/*
 * [25] Reverse Nodes in k-Group
 *
 * https://leetcode.com/problems/reverse-nodes-in-k-group
 *
 * Hard (30.51%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[]\n1'
 *
 *
 * Given a linked list, reverse the nodes of a linked list k at a time and
 * return its modified list.
 *
 *
 *
 * k is a positive integer and is less than or equal to the length of the
 * linked list. If the number of nodes is not a multiple of k then left-out
 * nodes in the end should remain as it is.
 *
 * You may not alter the values in the nodes, only nodes itself may be
 * changed.
 *
 * Only constant memory is allowed.
 *
 *
 * For example,
 * Given this linked list: 1->2->3->4->5
 *
 *
 *
 * For k = 2, you should return: 2->1->4->3->5
 *
 *
 *
 * For k = 3, you should return: 3->2->1->4->5
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 1;
        ListNode *tmpBegin = NULL;
        ListNode *tmpEnd = NULL;
        ListNode *cur = head;
        while(cur){
            if(count == 1){
                tmpBegin = cur;
            }else if(count == k){
                tmpEnd = cur;
                count = 1;
                reverseList(tmpBegin, tmpEnd);
            }
            count ++;
            cur = cur->next;
        }
        return head;
    }

    void reverseList(ListNode*& begin, ListNode*& end){
        if(begin == end) return;
        ListNode *cur = begin;
        ListNode *curNext = cur->next;
        while(curNext != end->next){
            cur = curNext->next;
            curNext->next = begin;
            begin = curNext;
            curNext = cur->next;
        }

    }
};

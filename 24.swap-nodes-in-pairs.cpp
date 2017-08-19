/*
 * [24] Swap Nodes in Pairs
 *
 * https://leetcode.com/problems/swap-nodes-in-pairs
 *
 * algorithms
 * Medium (38.25%)
 * Total Accepted:    171.9K
 * Total Submissions: 448.7K
 * Testcase Example:  '[]'
 *
 *
 * Given a linked list, swap every two adjacent nodes and return its head.
 *
 *
 *
 * For example,
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 *
 *
 *
 * Your algorithm should use only constant space. You may not modify the values
 * in the list, only nodes itself can be changed.
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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* tmpHead = new ListNode(INT_MAX);
        tmpHead->next = head;
        ListNode* pNode = tmpHead;
        ListNode* cNode = head;
        ListNode* nNode = cNode->next;
        while(cNode && nNode){
            cNode->next = nNode->next;
            nNode->next = cNode;
            pNode->next = nNode;
            pNode = cNode;
            cNode = cNode->next;
            if(cNode)
                nNode = cNode->next;
        }
        ListNode* newHead = tmpHead->next;
        delete tmpHead;
        return newHead;
    }
};

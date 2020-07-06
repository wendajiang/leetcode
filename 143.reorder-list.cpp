/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
 *
 * https://leetcode.com/problems/reorder-list/description/
 *
 * algorithms
 * Medium (33.01%)
 * Likes:    1184
 * Dislikes: 88
 * Total Accepted:    181.1K
 * Total Submissions: 548.1K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 * reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
 * 
 * You may not modify the values in the list's nodes, only nodes itself may be
 * changed.
 * 
 * Example 1:
 * 
 * 
 * Given 1->2->3->4, reorder it to 1->4->2->3.
 * 
 * Example 2:
 * 
 * 
 * Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr) {
            return ;
        }
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *p1 = &dummy, *p2 = &dummy;
        for (; p2 && p2->next; p1 = p1->next, p2 = p2->next->next);
        for (ListNode *prev = p1, *cur = p1->next; cur && cur->next; ) {
            ListNode *tmp = cur->next;
            cur->next = cur->next->next;
            tmp->next = prev->next;
            prev->next = tmp;
        }

        for (p2 = p1->next, p1->next = nullptr, p1= head; p2; ) {
            ListNode* tmp = p1->next;
            p1->next = p2;
            p2 = p2->next;
            p1->next->next = tmp;
            p1 = tmp;
        }
        
    }
};
// @lc code=end


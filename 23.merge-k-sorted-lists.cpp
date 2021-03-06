/*
 * [23] Merge k Sorted Lists
 *
 * https://leetcode.com/problems/merge-k-sorted-lists
 *
 * Hard (26.99%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[]'
 *
 *
 * Merge k sorted linked lists and return it as one sorted list. Analyze and
 * describe its complexity.
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
    ListNode *mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (NULL == l1) return l2;
        else if (NULL == l2) return l1;
        if (l1->val <= l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty()) return NULL;
        int len = lists.size();
        ListNode* p = lists[0];
        for(int i = 1; i < len; i++){
            p = mergeTwoLists(p, lists[i]);
        }
        return p;
        // while (len > 1) {
        //     for (int i = 0; i < len / 2; ++i) {
        //         lists[i] = mergeTwoLists(lists[i], lists[len - 1 - i]);
        //     }
        //     len = (len + 1) / 2;
        // }
        //
        // return lists.front();
    }

};

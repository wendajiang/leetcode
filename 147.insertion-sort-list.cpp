/*
 * @lc app=leetcode id=147 lang=cpp
 *
 * [147] Insertion Sort List
 *
 * https://leetcode.com/problems/insertion-sort-list/description/
 *
 * algorithms
 * Medium (39.09%)
 * Likes:    491
 * Dislikes: 529
 * Total Accepted:    172K
 * Total Submissions: 433.3K
 * Testcase Example:  '[4,2,1,3]'
 *
 * Sort a linked list using insertion sort.
 *
 *
 *
 *
 *
 * A graphical example of insertion sort. The partial sorted list (black)
 * initially contains only the first element in the list.
 * With each iteration one element (red) is removed from the input data and
 * inserted in-place into the sorted list
 *
 *
 *
 *
 *
 * Algorithm of Insertion Sort:
 *
 *
 * Insertion sort iterates, consuming one input element each repetition, and
 * growing a sorted output list.
 * At each iteration, insertion sort removes one element from the input data,
 * finds the location it belongs within the sorted list, and inserts it
 * there.
 * It repeats until no input elements remain.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: 4->2->1->3
 * Output: 1->2->3->4
 *
 *
 * Example 2:
 *
 *
 * Input: -1->5->3->4->0
 * Output: -1->0->3->4->5
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
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head) return head;
        ListNode *preHead = new ListNode(0);
        preHead->next = head;
        while(head && head->next) {
            if (head->val <= head->next->val) {
                head = head->next;
                continue;
            }
            ListNode* cur = preHead;
            while (cur->next->val <= head->next->val)
                cur = cur->next;
            if (cur != head) {
                ListNode* next = head->next;
                head->next = head->next->next;
                next->next = cur->next;
                cur->next = next;
            }
        }

        return preHead->next;
    }
};
// @lc code=end

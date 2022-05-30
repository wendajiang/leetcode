/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
 *
 * https://leetcode.com/problems/reverse-linked-list-ii/description/
 *
 * algorithms
 * Medium (42.55%)
 * Likes:    6187
 * Dislikes: 294
 * Total Accepted:    484.8K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,3,4,5]\n2\n4'
 *
 * Given the head of a singly linked list and two integers left and right where
 * left <= right, reverse the nodes of the list from position left to position
 * right, and return the reversed list.
 *
 *
 * Example 1:
 *
 *
 * Input: head = [1,2,3,4,5], left = 2, right = 4
 * Output: [1,4,3,2,5]
 *
 *
 * Example 2:
 *
 *
 * Input: head = [5], left = 1, right = 1
 * Output: [5]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the list is n.
 * 1 <= n <= 500
 * -500 <= Node.val <= 500
 * 1 <= left <= right <= n
 *
 *
 *
 * Follow up: Could you do it in one pass?
 */
#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// @lc code=start
class Solution {
   public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right || head == nullptr) return head;
        ListNode* guard = new ListNode(INT_MIN, head);
        ListNode *pre = guard, *cur = head;
        int cur_index = 1;
        ListNode* left_guard = nullptr;
        ListNode* right_guard = nullptr;
        while (cur_index != left && cur != nullptr) {
            pre = pre->next;
            cur = cur->next;
            cur_index++;
        }
        if (nullptr == cur) return head;
        left_guard = pre;

        while (cur_index != right && cur != nullptr) {
            cur = cur->next;
            cur_index++;
        }
        if (nullptr == cur) return head;
        right_guard = cur->next;

        pre = left_guard->next;
        cur = pre->next;
        ListNode* next = nullptr;
        while (cur && cur != right_guard) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        left_guard->next->next = right_guard;
        left_guard->next = pre;

        ListNode* res = guard->next;
        delete guard;
        return res;
    }
};
// @lc code=end

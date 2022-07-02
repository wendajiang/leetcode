/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (38.98%)
 * Likes:    19358
 * Dislikes: 3900
 * Total Accepted:    2.9M
 * Total Submissions: 7.4M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order, and each of their nodes
 * contains a single digit. Add the two numbers and return the sum as a linked
 * list.
 *
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 *
 *
 * Example 1:
 *
 *
 * Input: l1 = [2,4,3], l2 = [5,6,4]
 * Output: [7,0,8]
 * Explanation: 342 + 465 = 807.
 *
 *
 * Example 2:
 *
 *
 * Input: l1 = [0], l2 = [0]
 * Output: [0]
 *
 *
 * Example 3:
 *
 *
 * Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
 * Output: [8,9,9,9,0,0,0,1]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in each linked list is in the range [1, 100].
 * 0 <= Node.val <= 9
 * It is guaranteed that the list represents a number that does not have
 * leading zeros.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// @lc code=start
class Solution {
   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr && l2 == nullptr) {
            return nullptr;
        }

        if (l1 == nullptr && l2 != nullptr) {
            return l2;
        }
        if (l1 != nullptr && l2 == nullptr) {
            return l1;
        }
        ListNode* result = new ListNode((l1->val + l2->val) % 10);
        int carry = (l1->val + l2->val) / 10;
        ListNode* index = result;
        while (l1 != nullptr || l2 != nullptr) {
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
            // index = index->next;
            if (l1 != nullptr && l2 != nullptr) {
                index->next = new ListNode((l1->val + l2->val + carry) % 10);
                carry = (l1->val + l2->val + carry) / 10;
            } else if (l1 == nullptr && l2 != nullptr) {
                index->next = new ListNode((l2->val + carry) % 10);
                carry = (l2->val + carry) / 10;
            } else if (l1 != nullptr && l2 == nullptr) {
                index->next = new ListNode((l1->val + carry) % 10);
                carry = (l1->val + carry) / 10;
            } else {
                if (carry) index->next = new ListNode(carry);
            }
            index = index->next;
        }
        // if(carry)
        //     index->next = new ListNode(carry);
        return result;
    }
};
// @lc code=end
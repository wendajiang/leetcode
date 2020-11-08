/*
 * [141] Linked List Cycle
 *
 * https://leetcode.com/problems/linked-list-cycle
 *
 * Easy (35.39%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[]\nno cycle'
 *
 *
 * Given a linked list, determine if it has a cycle in it.
 *
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
#include <bits/stdc++.h>
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // return floyd(head);
        return brent(head);
    }

    bool floyd(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return false;
        bool res = false;
        ListNode* slow = head, *fast = head;
        while((fast != nullptr) && (slow != nullptr)) {
            slow = slow->next;
            if (fast->next) {
                fast = fast->next->next;
            }
            else {
                break;
            }
            if (fast == slow) {
                res = true;
                break;
            }
        }
        return res;
    }

    bool brent(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return false;
        int cnt = 0;
        ListNode* slow = head, *fast = head->next;
        bool res = false;
        while(slow && fast) {
            slow = fast;
            cnt++;
            int power_cnt = std::pow(2, cnt);
            for (int i = 0; i < power_cnt; i++) {
                fast = fast->next;
                if (fast == nullptr && i < power_cnt - 1) return false;
                if (fast == slow) return true;
            }
        }
        return res;
    }
};

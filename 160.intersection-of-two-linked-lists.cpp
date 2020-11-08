/*
 * [160] Intersection of Two Linked Lists
 *
 * https://leetcode.com/problems/intersection-of-two-linked-lists
 *
 * Easy (30.51%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  'No intersection: []\n[]'
 *
 * Write a program to find the node at which the intersection of two singly
 * linked lists begins.
 *
 * For example, the following two linked lists:
 *
 * A:          a1 → a2
 * ⁠                  ↘
 * ⁠                    c1 → c2 → c3
 * ⁠                  ↗
 * B:     b1 → b2 → b3
 *
 * begin to intersect at node c1.
 *
 * Notes:
 *
 * If the two linked lists have no intersection at all, return null.
 * The linked lists must retain their original structure after the function
 * returns.
 * You may assume there are no cycles anywhere in the entire linked structure.
 * Your code should preferably run in O(n) time and use only O(1) memory.
 *
 *
 *
 * Credits:Special thanks to @stellari for adding this problem and creating all
 * test cases.
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) return nullptr;
        ListNode* cur = headA;
        ListNode* end = nullptr;
        while(cur->next) {
            cur = cur->next;
        }
        end = cur;
        cur->next = headB;
        ListNode* slow = headA, *fast = headA;
        bool is_cycle = false;
        while(slow && fast) {
            slow = slow->next;
            if (fast->next) {
                fast = fast->next->next;
            }
            else {
                break;
            }
            if (slow == fast) {
                is_cycle = true;
                break;
            }
        }
        if (is_cycle) {
            slow = headA;
            while(slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            end->next = nullptr;
            return slow;
        }
        else {
            end->next = nullptr;
            return nullptr;
        }
    }
    // ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    //     int len1 = 0;
    //     int len2 = 0;
    //     ListNode* cur1 = headA;
    //     ListNode* cur2 = headB;
    //     while(cur1){
    //         len1++;
    //         cur1 = cur1->next;
    //     }
    //     cur1 = headA;
    //     while(cur2){
    //         len2++;
    //         cur2 = cur2->next;
    //     }
    //     cur2 = headB;
    //     if(len1 > len2){
    //         int tmp = len1 - len2;
    //         while(tmp){
    //             cur1 = cur1->next;
    //             tmp--;
    //         }
    //     }else if(len1 < len2){
    //         int tmp = len2 - len1;
    //         while(tmp){
    //             cur2 = cur2->next;
    //             tmp--;
    //         }
    //     }
    //     while(cur1 && cur2){
    //         if(cur1 == cur2){
    //             return cur1;
    //         }
    //         cur1 = cur1->next;
    //         cur2 = cur2->next;
    //     }
    //     return nullptr;
    // }
};

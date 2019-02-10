/*
 * [234] Palindrome Linked List
 *
 * https://leetcode.com/problems/palindrome-linked-list
 *
 * Easy (32.59%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[]'
 *
 * Given a singly linked list, determine if it is a palindrome.
 *
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
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
    //O(n) time O(1) space
    bool isPalindrome(ListNode* head){
        if(head == nullptr || head->next == nullptr) return true;
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast != nullptr){
            slow = slow->next;
        }
        slow = reverseList(slow);
        fast = head;
        while(slow){
            if(fast->val != slow->val)
                return false;
            slow = slow->next;
            fast = fast->next;
        }
        return true;
    }

    ListNode* reverseList(ListNode* head){
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode *preHead = new ListNode(INT_MIN);
        preHead->next = head;
        ListNode *pre = preHead, *cur = preHead->next, *curNext = cur->next;
        while(curNext){
            cur->next = curNext->next;
            curNext->next = preHead->next;
            preHead->next = curNext;
            curNext = cur->next;
        }
        ListNode *tmpHead = preHead->next;
        delete preHead;
        return tmpHead;
    }


    // // naive的解法
    // bool isPalindrome(ListNode* head) {
    //     if(head == nullptr || head->next == nullptr) return true;
    //     ListNode *slow = head;
    //     ListNode *fast = head;
    //     stack<int> st;
    //     while(fast && fast->next){
    //         st.push(slow->val);
    //         slow = slow->next;
    //         fast = fast->next->next;
    //     }
    //     //如果链表有奇数个元素，或者只有两个元素
    //     if(fast != nullptr)
    //         slow = slow->next;
    //     // if(st.size() != 1 && (st.size() & 1) != 0){
    //     //     slow = slow->next;
    //     // }
    //     while(slow){
    //         if(slow->val != st.top())
    //             return false;
    //         st.pop();
    //         slow = slow->next;
    //     }
    //     return true;
    // }
};

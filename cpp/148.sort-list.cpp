/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
 *
 * https://leetcode.com/problems/sort-list/description/
 *
 * algorithms
 * Medium (45.66%)
 * Likes:    3712
 * Dislikes: 160
 * Total Accepted:    326.5K
 * Total Submissions: 714.8K
 * Testcase Example:  '[4,2,1,3]'
 *
 * Given the head of a linked list, return the list after sorting it in
 * ascending order.
 * 
 * Follow up: Can you sort the linked list in O(n logn) time and O(1) memory
 * (i.e. constant space)?
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [4,2,1,3]
 * Output: [1,2,3,4]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = [-1,5,3,4,0]
 * Output: [-1,0,3,4,5]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: head = []
 * Output: []
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the list is in the range [0, 5 * 10^4].
 * -10^5 <= Node.val <= 10^5
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // @todo 复习排序
    ListNode* sortList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        int length = 0;
        ListNode* node = head;
        while (node != nullptr) {
            length++;
            node = node->next;
        }
        ListNode* dummyHead = new ListNode(0, head);
        for (int subLength = 1; subLength < length; subLength <<= 1) {
            ListNode* prev = dummyHead, *curr = dummyHead->next;
            while (curr != nullptr) {
                ListNode* head1 = curr;
                for (int i = 1; i < subLength && curr->next != nullptr; i++) {
                    curr = curr->next;
                }
                ListNode* head2 = curr->next;
                curr->next = nullptr;
                curr = head2;
                for (int i = 1; i < subLength && curr != nullptr && curr->next != nullptr; i++) {
                    curr = curr->next;
                }
                ListNode* next = nullptr;
                if (curr != nullptr) {
                    next = curr->next;
                    curr->next = nullptr;
                }
                ListNode* merged = merge(head1, head2);
                prev->next = merged;
                while (prev->next != nullptr) {
                    prev = prev->next;
                }
                curr = next;
            }
        }
        return dummyHead->next;
    }

    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* temp = dummyHead, *temp1 = head1, *temp2 = head2;
        while (temp1 != nullptr && temp2 != nullptr) {
            if (temp1->val <= temp2->val) {
                temp->next = temp1;
                temp1 = temp1->next;
            } else {
                temp->next = temp2;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
        if (temp1 != nullptr) {
            temp->next = temp1;
        } else if (temp2 != nullptr) {
            temp->next = temp2;
        }
        return dummyHead->next;
    }


/* quicksort TLE
    ListNode* sortList(ListNode* head) {
        ListNode* new_head = quickSortRecur(head, getTail(head));
        return new_head;
    }

    // Returns the last node of the list 
    struct ListNode *getTail(struct ListNode *cur) 
    { 
        while (cur != NULL && cur->next != NULL) 
            cur = cur->next; 
        return cur; 
    } 
    
    // Partitions the list taking the last element as the pivot 
    struct ListNode *partition(struct ListNode *head, struct ListNode *end, 
                        struct ListNode **newHead, struct ListNode **newEnd) 
    { 
        struct ListNode *pivot = end; 
        struct ListNode *prev = NULL, *cur = head, *tail = pivot; 
    
        // During partition, both the head and end of the list might change 
        // which is updated in the newHead and newEnd variables 
        while (cur != pivot) 
        { 
            if (cur->val < pivot->val)
            { 
                // First node that has a value less than the pivot - becomes 
                // the new head 
                if ((*newHead) == NULL) 
                    (*newHead) = cur; 
    
                prev = cur;  
                cur = cur->next; 
            } 
            else // If cur node is greater than pivot 
            { 
                // Move cur node to next of tail, and change tail 
                if (prev) 
                    prev->next = cur->next; 
                struct ListNode *tmp = cur->next; 
                cur->next = NULL; 
                tail->next = cur; 
                tail = cur; 
                cur = tmp; 
            } 
        } 
    
        // If the pivot data is the smallest element in the current list, 
        // pivot becomes the head 
        if ((*newHead) == NULL) 
            (*newHead) = pivot; 
    
        // Update newEnd to the current last node 
        (*newEnd) = tail; 
    
        // Return the pivot node 
        return pivot; 
    } 
    
    
    //here the sorting happens exclusive of the end node 
    struct ListNode *quickSortRecur(struct ListNode *head, struct ListNode *end) 
    { 
        // base condition 
        if (!head || head == end) 
            return head; 
    
        ListNode *newHead = NULL, *newEnd = NULL; 
    
        // Partition the list, newHead and newEnd will be updated 
        // by the partition function 
        struct ListNode *pivot = partition(head, end, &newHead, &newEnd); 
    
        // If pivot is the smallest element - no need to recur for 
        // the left part. 
        if (newHead != pivot) 
        { 
            // Set the node before the pivot node as NULL 
            struct ListNode *tmp = newHead; 
            while (tmp->next != pivot) 
                tmp = tmp->next; 
            tmp->next = NULL; 
    
            // Recur for the list before pivot 
            newHead = quickSortRecur(newHead, tmp); 
    
            // Change next of last node of the left half to pivot 
            tmp = getTail(newHead); 
            tmp->next = pivot; 
        } 
    
        // Recur for the list after the pivot element 
        pivot->next = quickSortRecur(pivot->next, newEnd); 
    
        return newHead; 
    } 
*/

};
// @lc code=end


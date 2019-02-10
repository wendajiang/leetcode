/*
 * [86] Partition List
 *
 * https://leetcode.com/problems/partition-list/description/
 *
 * algorithms
 * Medium (33.53%)
 * Total Accepted:    122.4K
 * Total Submissions: 364.8K
 * Testcase Example:  '[1,4,3,2,5,2]\n3'
 *
 * Given a linked list and a value x, partition it such that all nodes less
 * than x come before nodes greater than or equal to x.
 *
 * You should preserve the original relative order of the nodes in each of the
 * two partitions.
 *
 * Example:
 *
 *
 * Input: head = 1->4->3->2->5->2, x = 3
 * Output: 1->2->2->4->3->5
 *
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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL) return NULL;
        vector<int> left;
        vector<int> right;
        ListNode* hh = head;
        while(hh){
            if(hh->val < x) left.push_back(hh->val);
            else if(hh->val >= x) right.push_back(hh->val);
            hh = hh->next;
        }
        ListNode* nhead;
        if(left.size() == 0){
            hh = new ListNode(right[0]);
            nhead = hh;
            for(int i = 1; i < right.size(); i++){
                hh->next = new ListNode(right[i]);
                hh = hh->next;
            }
        }else{
            hh = new ListNode(left[0]);
            nhead = hh;
            for(int i = 1; i < left.size(); i++){
                hh->next = new ListNode(left[i]);
                hh = hh->next;
            }
            for(int i = 0; i < right.size(); i++){
                hh->next = new ListNode(right[i]);
                hh = hh->next;
            }
        }
        return nhead;
    }
};

/*
 * [138] Copy List with Random Pointer
 *
 * https://leetcode.com/problems/copy-list-with-random-pointer
 *
 * Medium (26.35%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '{}'
 *
 *
 * A linked list is given such that each node contains an additional random
 * pointer which could point to any node in the list or null.
 *
 *
 *
 * Return a deep copy of the list.
 *
 */
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL) return NULL;
        //copy the list
        RandomListNode *cur = head;
        while(cur){
            RandomListNode *tmp = new RandomListNode(cur->label);
            tmp->next = cur->next;
            cur->next = tmp;
            cur = cur->next->next;
        }
        //copy the random pointer
        cur = head;
        while(cur){
            if(cur->random)
                cur->next->random = cur->random->next;
            cur = cur->next->next;
        }

        //split the list to two lists
        cur = head;
        RandomListNode *nhead = cur->next;
        RandomListNode *tmp = nhead;
        cur->next = cur->next->next;
        cur = cur->next;
        while(cur){
            tmp->next = cur->next;
            tmp = tmp->next;
            cur->next = cur->next->next;
            cur = cur->next;
        }
        return nhead;
    }
};

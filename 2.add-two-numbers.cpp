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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr && l2 == nullptr){
            return nullptr;
        }
        
        if(l1 == nullptr && l2 != nullptr){
            return l2;
        }
        if(l1 != nullptr && l2 == nullptr){
            return l1;
        }
        ListNode* result = new ListNode((l1->val + l2->val) % 10);
        int carry = (l1->val + l2->val) / 10;
        ListNode* index = result;
        while(l1 != nullptr || l2 != nullptr){
            if(l1 != nullptr)
                l1 = l1->next;
            if(l2 != nullptr)
                l2 = l2->next;
            // index = index->next;
            if(l1 != nullptr && l2 != nullptr){
                index->next = new ListNode((l1->val + l2->val + carry) % 10);
                carry = (l1->val + l2->val + carry) / 10;
            }else if(l1 == nullptr && l2 != nullptr){
                index->next = new ListNode((l2->val + carry) % 10);
                carry = (l2->val + carry) / 10;
            }else if(l1 != nullptr && l2 == nullptr){
                index->next = new ListNode((l1->val + carry) % 10);
                carry = (l1->val + carry) / 10;
            }else{
                if(carry)
                    index->next = new ListNode(carry);
            }
            index = index->next;
        }
        // if(carry)
        //     index->next = new ListNode(carry);
        return result;
    }
};
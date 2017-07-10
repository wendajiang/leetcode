 /*
 * [25] Reverse Nodes in k-Group
 *
 * https://leetcode.com/problems/reverse-nodes-in-k-group
 *
 * Hard (30.51%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[]\n1'
 *
 *
 * Given a linked list, reverse the nodes of a linked list k at a time and
 * return its modified list.
 *
 *
 *
 * k is a positive integer and is less than or equal to the length of the
 * linked list. If the number of nodes is not a multiple of k then left-out
 * nodes in the end should remain as it is.
 *
 * You may not alter the values in the nodes, only nodes itself may be
 * changed.
 *
 * Only constant memory is allowed.
 *
 *
 * For example,
 * Given this linked list: 1->2->3->4->5
 *
 *
 *
 * For k = 2, you should return: 2->1->4->3->5
 *
 *
 *
 * For k = 3, you should return: 3->2->1->4->5
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || k == 1) return head;
        int num = 0;
        ListNode * preHead = new ListNode(INT_MIN);
        preHead->next = head;
        ListNode *cur = head, *curNext = NULL, *pre = preHead;
        while(cur){
            num++;
            cur = cur->next;
        }
        while(num >= k){
            cur = pre->next;
            curNext = cur->next;
            for(int i = 1; i < k; i++){
                cur->next = curNext->next;
                curNext->next = pre->next;
                pre->next = curNext;
                curNext = cur->next;
            }
            pre = cur;
            num -= k;
        }
        ListNode *tmpHead = preHead;
        delete preHead;
        return tmpHead->next;
    }

};

/*
    可以看到加一个头结点好处理的多
*/

/*
    有问题的解法，其中学到了了引用传递的问题，需要去细细琢磨
    每次传完之后就很难处理，从begin到end之间反转实现了的
    但是每次跳出子函数后，值需要重新复制，如果继续改进，需要加很多变量
    很不清晰

    思路记录：很navie，就是写一个从begin到end的子函数，不断调用
        子函数没能实现
*/
// void reverseList(ListNode *&begin, ListNode *&end){
//     if(begin == end)return;
//     ListNode *cur = begin;
//     ListNode *tmpEnd = end->next;
//     ListNode *cNext = cur->next;
//     while(cNext != tmpEnd){
//         cur->next = cNext->next;
//         cNext->next = begin;
//         begin = cNext;
//         cNext = cur->next;
//     }
// //    return begin;
// }
// ListNode* reverseKGroup(ListNode *head, int k){
//     int count = 1;
//     ListNode *tmpBegin = NULL;
//     ListNode *tmpEnd = NULL;
//     ListNode *cur = head;
//     bool isFirst = true;
//     while(cur){
//         if(count == 1){
//             tmpBegin = cur;
//         }else if(count == k){
//             tmpEnd = cur;
//             count = 1;
//             reverseList(tmpBegin, tmpEnd);
//             if(isFirst){
//                 head = tmpBegin;
//                 isFirst = false;
//             }else{
//
//             }
//
//
//             cur = cur->next;
//             continue;
//         }
//         count++;
//         cur = cur->next;
//     }
//     return head;
// }

/*
    有问题解法的思路，不过可以实现，通过递归的方式
    ListNode* reverse(ListNode* first, ListNode* last)
        {
            ListNode* prev = last;

            while ( first != last )
            {
                auto tmp = first->next;
                first->next = prev;
                prev = first;
                first = tmp;
            }

            return prev;
        }

        ListNode* reverseKGroup(ListNode* head, int k)
        {
            auto node=head;
            for (int i=0; i < k; ++i)
            {
                if ( ! node  )
                    return head; // nothing to do list too sort
                node = node->next;
            }

            auto new_head = reverse( head, node);
            head->next = reverseKGroup( node, k);
            return new_head;
        }
*/
/*
    仍然是有问题的思路，另一种实现方式

    ListNode* reverseKGroup(ListNode* head, int k) {

    ListNode *p1=head,*p2=head;
    ListNode *first=NULL,*cur=head;
    int n=0;
    while(p1)
    {
        p1=p1->next;
        n++;
    }
    n=n/k;
    if(n==0||k==1) return head;
    for(int i=0;i<n;i++)
    {
        ListNode *prev=NULL,*next=NULL;
        int l=1;
        p1=cur;
        while(l++<=k)
        {
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        if(i>=1)
            first->next=prev;
        else
            p2=prev;
        first=p1;
    }
    first->next=cur;
    return p2;
}

*/

/*
 * @lc app=leetcode id=1019 lang=cpp
 *
 * [1019] Next Greater Node In Linked List
 *
 * https://leetcode.com/problems/next-greater-node-in-linked-list/description/
 *
 * algorithms
 * Medium (59.22%)
 * Likes:    1729
 * Dislikes: 86
 * Total Accepted:    86.3K
 * Total Submissions: 145.7K
 * Testcase Example:  '[2,1,5]'
 *
 * You are given the head of a linked list with n nodes.
 *
 * For each node in the list, find the value of the next greater node. That is,
 * for each node, find the value of the first node that is next to it and has a
 * strictly larger value than it.
 *
 * Return an integer array answer where answer[i] is the value of the next
 * greater node of the i^th node (1-indexed). If the i^th node does not have a
 * next greater node, set answer[i] = 0.
 *
 *
 * Example 1:
 *
 *
 * Input: head = [2,1,5]
 * Output: [5,5,0]
 *
 *
 * Example 2:
 *
 *
 * Input: head = [2,7,4,3,5]
 * Output: [7,0,5,5,0]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the list is n.
 * 1 <= n <= 10^4
 * 1 <= Node.val <= 10^9
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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> res, nums;
        stack<int> st;
        int cnt = 0;
        while(head) {
            nums.push_back(head->val);
            while(!st.empty() && head->val > nums[st.top()]) {
                res[st.top()] = head->val;
                st.pop();
            }
            st.push(cnt);
            res.resize(++cnt);
            head = head->next;
        }
        return res;

    }
};
// @lc code=end

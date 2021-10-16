/*
 * @lc app=leetcode id=817 lang=cpp
 *
 * [817] Linked List Components
 *
 * https://leetcode.com/problems/linked-list-components/description/
 *
 * algorithms
 * Medium (57.91%)
 * Likes:    593
 * Dislikes: 1572
 * Total Accepted:    62.3K
 * Total Submissions: 107.5K
 * Testcase Example:  '[0,1,2,3]\n[0,1,3]'
 *
 * You are given the head of a linked list containing unique integer values and
 * an integer array nums that is a subset of the linked list values.
 *
 * Return the number of connected components in nums where two values are
 * connected if they appear consecutively in the linked list.
 *
 *
 * Example 1:
 *
 *
 * Input: head = [0,1,2,3], nums = [0,1,3]
 * Output: 2
 * Explanation: 0 and 1 are connected, so [0, 1] and [3] are the two connected
 * components.
 *
 *
 * Example 2:
 *
 *
 * Input: head = [0,1,2,3,4], nums = [0,3,1,4]
 * Output: 2
 * Explanation: 0 and 1 are connected, 3 and 4 are connected, so [0, 1] and [3,
 * 4] are the two connected components.
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the linked list is n.
 * 1 <= n <= 10^4
 * 0 <= Node.val < n
 * All the values Node.val are unique.
 * 1 <= nums.length <= n
 * 0 <= nums[i] < n
 * All the values of nums are unique.
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
    int numComponents(ListNode* head, vector<int>& nums) {
        set<int> s;
        for (auto n : nums) {
            s.insert(n);
        }
        int cnt = 0;
        int res = 0;
        ListNode *cur = head;
        while(cur) {
            if (s.count(cur->val) && cnt == 0) {
                res++;
                cnt++;
            } else if(s.count(cur->val) && cnt > 0) {
                cnt++;
            } else if (!s.count(cur->val) && cnt > 0) {
                cnt = 0;
            }
            cur = cur->next;
        }
        return res;

    }
};
// @lc code=end

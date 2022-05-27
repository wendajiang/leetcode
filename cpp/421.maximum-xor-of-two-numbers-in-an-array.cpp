/*
 * @lc app=leetcode id=421 lang=cpp
 *
 * [421] Maximum XOR of Two Numbers in an Array
 *
 * https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/description/
 *
 * algorithms
 * Medium (53.69%)
 * Likes:    1843
 * Dislikes: 205
 * Total Accepted:    76.5K
 * Total Submissions: 142K
 * Testcase Example:  '[3,10,5,25,2,8]'
 *
 * Given an integer array nums, return the maximum result of nums[i] XOR
 * nums[j], where 0 ≤ i ≤ j < n.
 * 
 * Follow up: Could you do this in O(n) runtime?
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [3,10,5,25,2,8]
 * Output: 28
 * Explanation: The maximum result is 5 XOR 25 = 28.
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [0]
 * Output: 0
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [2,4]
 * Output: 6
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: nums = [8,10,2]
 * Output: 10
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: nums = [14,70,53,83,49,91,36,80,92,51,66,70]
 * Output: 127
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 2 * 10^4
 * 0 <= nums[i] <= 2^31 - 1
 * 
 * 
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    struct node {
        node *ch[2];
        node() {
            fill_n(ch, 2, nullptr);
        }
    };

    vector<node> tree;

    int findMaximumXOR(vector<int>& nums) {
        node *root = new node();
        node* p = root;
        int maxxor = 0;
        int ans = 0;
        node* q = root;
        for (int i = 0; i < nums.size(); i++) {
            p = root;
            q = root;
            ans = 0;
            for (int j = 30; j >= 0; j--) {
                ans <<= 1;
                int tmp = (nums[i] >> j) & 0x1;
                if (p->ch[tmp] == nullptr) p->ch[tmp] = new node();
                p = p->ch[tmp];

                if (q->ch[1 - tmp] != nullptr) {
                    q = q->ch[1 - tmp];
                    ans += 1;
                }
                else {
                    q = q->ch[tmp];
                }
                
            }
            maxxor = max(maxxor, ans);
        }

        return maxxor;
    }
};
// @lc code=end


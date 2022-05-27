/*
 * @lc app=leetcode id=228 lang=cpp
 *
 * [228] Summary Ranges
 *
 * https://leetcode.com/problems/summary-ranges/description/
 *
 * algorithms
 * Easy (41.98%)
 * Likes:    879
 * Dislikes: 645
 * Total Accepted:    199.7K
 * Total Submissions: 475.4K
 * Testcase Example:  '[0,1,2,4,5,7]'
 *
 * You are given a sorted unique integer array nums.
 * 
 * Return the smallest sorted list of ranges that cover all the numbers in the
 * array exactly. That is, each element of nums is covered by exactly one of
 * the ranges, and there is no integer x such that x is in one of the ranges
 * but not in nums.
 * 
 * Each range [a,b] in the list should be output as:
 * 
 * 
 * "a->b" if a != b
 * "a" if a == b
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [0,1,2,4,5,7]
 * Output: ["0->2","4->5","7"]
 * Explanation: The ranges are:
 * [0,2] --> "0->2"
 * [4,5] --> "4->5"
 * [7,7] --> "7"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [0,2,3,4,6,8,9]
 * Output: ["0","2->4","6","8->9"]
 * Explanation: The ranges are:
 * [0,0] --> "0"
 * [2,4] --> "2->4"
 * [6,6] --> "6"
 * [8,9] --> "8->9"
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = []
 * Output: []
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: nums = [-1]
 * Output: ["-1"]
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: nums = [0]
 * Output: ["0"]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= nums.length <= 20
 * -2^31 <= nums[i] <= 2^31 - 1
 * All the values of nums are unique.
 * nums is sorted in ascending order.
 * 
 * 
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int len = nums.size(), l = 0, r = 0;
        vector<string> ans;
        while(r < len) {
            r++;
            while (r < len && nums[r] == nums[r - 1] + 1) r++;
            if (l == r - 1) ans.push_back(to_string(nums[l]));
            else {
                ans.push_back(to_string(nums[l]) + "->" + to_string(nums[r - 1]));
            }
            l = r;
        }
        return ans;
    }
};
// @lc code=end


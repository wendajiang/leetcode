/*
 * @lc app=leetcode id=1512 lang=cpp
 *
 * [1512] Number of Good Pairs
 *
 * https://leetcode.com/problems/number-of-good-pairs/description/
 *
 * algorithms
 * Easy (87.67%)
 * Likes:    1995
 * Dislikes: 129
 * Total Accepted:    251.3K
 * Total Submissions: 286.4K
 * Testcase Example:  '[1,2,3,1,1,3]'
 *
 * Given an array of integers nums, return the number of good pairs.
 *
 * A pair (i, j) is called good if nums[i] == nums[j] and i < j.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,3,1,1,3]
 * Output: 4
 * Explanation: There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,1,1,1]
 * Output: 6
 * Explanation: Each pair in the array are good.
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [1,2,3]
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 100
 * 1 <= nums[i] <= 100
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
   public:
    int numIdenticalPairs(vector<int>& nums) {
        int test[101];
        memset(test, 0, sizeof(test));
        for (auto num : nums) {
            test[num]++;
        }
        int res = 0;
        for (int i = 0; i < 101; i++) {
            if (test[i] > 1) {
                res += (test[i] * (test[i] - 1) / 2);
            }
        }
        return res;
    }
};
// @lc code=end

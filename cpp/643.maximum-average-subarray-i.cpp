/*
 * @lc app=leetcode id=643 lang=cpp
 *
 * [643] Maximum Average Subarray I
 *
 * https://leetcode.com/problems/maximum-average-subarray-i/description/
 *
 * algorithms
 * Easy (41.96%)
 * Likes:    1139
 * Dislikes: 145
 * Total Accepted:    109.9K
 * Total Submissions: 258.4K
 * Testcase Example:  '[1,12,-5,-6,50,3]\n4'
 *
 * You are given an integer array nums consisting of n elements, and an integer
 * k.
 *
 * Find a contiguous subarray whose length is equal to k that has the maximum
 * average value and return this value. Any answer with a calculation error
 * less than 10^-5 will be accepted.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,12,-5,-6,50,3], k = 4
 * Output: 12.75000
 * Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [5], k = 1
 * Output: 5.00000
 *
 *
 *
 * Constraints:
 *
 *
 * n == nums.length
 * 1 <= k <= n <= 10^5
 * -10^4 <= nums[i] <= 10^4
 *
 *
 */

// @lc code=start
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        vector<int> sum(nums.size());
        sum[0] = nums[0];
        int max_find = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            sum[i] = sum[i - 1] + nums[i];
            if (i == k - 1) {
                max_find = sum[i] - 0;
            } else if (i >= k) {
                max_find = std::max(max_find, sum[i] - sum[i - k]);
            }
        }
        return (double)max_find / k;

    }
};
// @lc code=end

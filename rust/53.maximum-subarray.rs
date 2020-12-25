/*
 * @lc app=leetcode id=53 lang=rust
 *
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (47.28%)
 * Likes:    9959
 * Dislikes: 479
 * Total Accepted:    1.2M
 * Total Submissions: 2.6M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * Given an integer array nums, find the contiguous subarray (containing at
 * least one number) which has the largest sum and return its sum.
 *
 * Follow up: If you have figured out the O(n) solution, try coding another
 * solution using the divide and conquer approach, which is more subtle.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1]
 * Output: 1
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [0]
 * Output: 0
 *
 *
 * Example 4:
 *
 *
 * Input: nums = [-1]
 * Output: -1
 *
 *
 * Example 5:
 *
 *
 * Input: nums = [-2147483647]
 * Output: -2147483647
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 2 * 10^4
 * -2^31 <= nums[i] <= 2^31 - 1
 *
 *
 */

// @lc code=start
impl Solution {
    pub fn max_sub_array(nums: Vec<i32>) -> i32 {
        let mut sum = 0;
        let mut max_sum = nums[0];
        for num in nums {
            if sum < 0 {
                sum = num;
            }
            else {
                sum += num;
            }
            if sum > max_sum {
                max_sum = sum;
            }
        }
        return max_sum;
    }
}
// @lc code=end

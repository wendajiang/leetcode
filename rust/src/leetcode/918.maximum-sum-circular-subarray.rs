/*
 * @lc app=leetcode id=918 lang=rust
 *
 * [918] Maximum Sum Circular Subarray
 *
 * https://leetcode.com/problems/maximum-sum-circular-subarray/description/
 *
 * algorithms
 * Medium (35.68%)
 * Likes:    2363
 * Dislikes: 99
 * Total Accepted:    89.9K
 * Total Submissions: 251.7K
 * Testcase Example:  '[1,-2,3,-2]'
 *
 * Given a circular integer array nums of length n, return the maximum possible
 * sum of a non-empty subarray of nums.
 * 
 * A circular array means the end of the array connects to the beginning of the
 * array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the
 * previous element of nums[i] is nums[(i - 1 + n) % n].
 * 
 * A subarray may only include each element of the fixed buffer nums at most
 * once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there
 * does not exist i <= k1, k2 <= j with k1 % n == k2 % n.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,-2,3,-2]
 * Output: 3
 * Explanation: Subarray [3] has maximum sum 3
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [5,-3,5]
 * Output: 10
 * Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [3,-1,2,-1]
 * Output: 4
 * Explanation: Subarray [2,-1,3] has maximum sum 2 + (-1) + 3 = 4
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: nums = [3,-2,2,-3]
 * Output: 3
 * Explanation: Subarray [3] and [3,-2,2] both have maximum sum 3
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: nums = [-2,-3,-1]
 * Output: -1
 * Explanation: Subarray [-1] has maximum sum -1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == nums.length
 * 1 <= n <= 3 * 10^4
 * -3 * 10^4 <= nums[i] <= 3 * 10^4
 * 
 * 
 */

// @lc code=start
impl Solution {
    pub fn max_subarray_sum_circular(nums: Vec<i32>) -> i32 {
        let mut total = 0;
        let mut max_sum = nums[0];
        let mut cur_max = 0;
        let mut min_sum = nums[0];
        let mut cur_min = 0;
        for num in nums {
            cur_max = num.max(cur_max + num);
            max_sum = max_sum.max(cur_max);
            cur_min = num.min(cur_min + num);
            min_sum = min_sum.min(cur_min);
            total += num;
        }
        match max_sum > 0 {
            true => max_sum.max(total - min_sum),
            false => max_sum,
        }
    }
}
// @lc code=end

struct Solution;

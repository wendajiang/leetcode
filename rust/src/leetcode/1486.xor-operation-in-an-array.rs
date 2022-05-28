/*
 * @lc app=leetcode id=1486 lang=rust
 *
 * [1486] XOR Operation in an Array
 *
 * https://leetcode.com/problems/xor-operation-in-an-array/description/
 *
 * algorithms
 * Easy (84.04%)
 * Likes:    695
 * Dislikes: 272
 * Total Accepted:    110.9K
 * Total Submissions: 131.8K
 * Testcase Example:  '5\n0'
 *
 * You are given an integer n and an integer start.
 *
 * Define an array nums where nums[i] = start + 2 * i (0-indexed) and n ==
 * nums.length.
 *
 * Return the bitwise XOR of all elements of nums.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 5, start = 0
 * Output: 8
 * Explanation: Array nums is equal to [0, 2, 4, 6, 8] where (0 ^ 2 ^ 4 ^ 6 ^
 * 8) = 8.
 * Where "^" corresponds to bitwise XOR operator.
 *
 *
 * Example 2:
 *
 *
 * Input: n = 4, start = 3
 * Output: 8
 * Explanation: Array nums is equal to [3, 5, 7, 9] where (3 ^ 5 ^ 7 ^ 9) =
 * 8.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 1000
 * 0 <= start <= 1000
 * n == nums.length
 *
 *
 */
struct Solution;
// @lc code=start
impl Solution {
    pub fn xor_operation(n: i32, start: i32) -> i32 {
        (1..n).fold(start, |acc, i| acc ^ start + 2 * i as i32)
    }
}
// @lc code=end

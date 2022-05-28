/*
 * @lc app=leetcode id=7 lang=rust
 *
 * [7] Reverse Integer
 *
 * https://leetcode.com/problems/reverse-integer/description/
 *
 * algorithms
 * Medium (26.20%)
 * Likes:    6288
 * Dislikes: 9073
 * Total Accepted:    1.9M
 * Total Submissions: 7.2M
 * Testcase Example:  '123'
 *
 * Given a signed 32-bit integer x, return x with its digits reversed. If
 * reversing x causes the value to go outside the signed 32-bit integer range
 * [-2^31, 2^31 - 1], then return 0.
 *
 * Assume the environment does not allow you to store 64-bit integers (signed
 * or unsigned).
 *
 *
 * Example 1:
 *
 *
 * Input: x = 123
 * Output: 321
 *
 *
 * Example 2:
 *
 *
 * Input: x = -123
 * Output: -321
 *
 *
 * Example 3:
 *
 *
 * Input: x = 120
 * Output: 21
 *
 *
 *
 * Constraints:
 *
 *
 * -2^31 <= x <= 2^31 - 1
 *
 *
 */

struct Solution;

// @lc code=start
impl Solution {
    pub fn reverse(mut x: i32) -> i32 {
        || -> Option<i32> {
            let mut ret = 0i32;
            while x.abs() != 0 {
                ret = ret.checked_mul(10)?.checked_add(x % 10)?;
                x /= 10;
            }
            Some(ret)
        }()
        .unwrap_or(0)
    }
}
// @lc code=end

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_base() {
        assert_eq!(321, Solution::reverse(123));
    }
}

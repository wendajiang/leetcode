/*
 * @lc app=leetcode id=166 lang=rust
 *
 * [166] Fraction to Recurring Decimal
 *
 * https://leetcode.com/problems/fraction-to-recurring-decimal/description/
 *
 * algorithms
 * Medium (23.09%)
 * Likes:    1400
 * Dislikes: 2667
 * Total Accepted:    168.9K
 * Total Submissions: 730.5K
 * Testcase Example:  '1\n2'
 *
 * Given two integers representing the numerator and denominator of a fraction,
 * return the fraction in string format.
 *
 * If the fractional part is repeating, enclose the repeating part in
 * parentheses.
 *
 * If multiple answers are possible, return any of them.
 *
 * It is guaranteed that the length of the answer string is less than 10^4 for
 * all the given inputs.
 *
 *
 * Example 1:
 * Input: numerator = 1, denominator = 2
 * Output: "0.5"
 * Example 2:
 * Input: numerator = 2, denominator = 1
 * Output: "2"
 * Example 3:
 * Input: numerator = 2, denominator = 3
 * Output: "0.(6)"
 * Example 4:
 * Input: numerator = 4, denominator = 333
 * Output: "0.(012)"
 * Example 5:
 * Input: numerator = 1, denominator = 5
 * Output: "0.2"
 *
 *
 * Constraints:
 *
 *
 * -2^31 <= numerator, denominator <= 2^31 - 1
 * denominator != 0
 *
 *
 */

// @lc code=start
use std::collections::HashMap;
use std::iter::FromIterator;

impl Solution {
    pub fn fraction_to_decimal(numerator: i32, denominator: i32) -> String {
        if numerator == 0 {
            return "0".to_string();
        }

        let mut res: Vec<char> = vec![];
        if (numerator < 0) ^ (denominator < 0) {
            res.push('-');
        }
        let n = (numerator as i64).abs();
        let d = (denominator as i64).abs();
        res.append(&mut format!("{}", n / d).chars().collect());

        let mut r = n % d;
        if r == 0 {
            return String::from_iter(res);
        }
        res.push('.');
        let mut hs: HashMap<i64, usize> = HashMap::new();
        while r != 0 {
            if let Some(index) = hs.insert(r, res.len()) {
                res.insert(index, '(');
                res.push(')');
                break;
            }
            r *= 10;
            res.append(&mut format!("{}", r / d).chars().collect());
            r %= d;
        }
        String::from_iter(res)
    }
}
// @lc code=end

struct Solution;

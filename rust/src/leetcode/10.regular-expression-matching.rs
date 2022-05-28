/*
 * @lc app=leetcode id=10 lang=rust
 *
 * [10] Regular Expression Matching
 *
 * https://leetcode.com/problems/regular-expression-matching/description/
 *
 * algorithms
 * Hard (28.02%)
 * Likes:    8173
 * Dislikes: 1243
 * Total Accepted:    686.2K
 * Total Submissions: 2.4M
 * Testcase Example:  '"aa"\n"a"'
 *
 * Given an input string s and a pattern p, implement regular expression
 * matching with support for '.' and '*' where:
 *
 *
 * '.' Matches any single character.​​​​
 * '*' Matches zero or more of the preceding element.
 *
 *
 * The matching should cover the entire input string (not partial).
 *
 *
 * Example 1:
 *
 *
 * Input: s = "aa", p = "a"
 * Output: false
 * Explanation: "a" does not match the entire string "aa".
 *
 *
 * Example 2:
 *
 *
 * Input: s = "aa", p = "a*"
 * Output: true
 * Explanation: '*' means zero or more of the preceding element, 'a'.
 * Therefore, by repeating 'a' once, it becomes "aa".
 *
 *
 * Example 3:
 *
 *
 * Input: s = "ab", p = ".*"
 * Output: true
 * Explanation: ".*" means "zero or more (*) of any character (.)".
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 20
 * 1 <= p.length <= 30
 * s contains only lowercase English letters.
 * p contains only lowercase English letters, '.', and '*'.
 * It is guaranteed for each appearance of the character '*', there will be a
 * previous valid character to match.
 *
 *
 */
struct Solution;

// @lc code=start
impl Solution {
    pub fn is_match(s: String, p: String) -> bool {
        let n = s.len();
        let m = p.len();
        let s: Vec<char> = s.chars().collect();
        let p: Vec<char> = p.chars().collect();
        let mut memo: Vec<Vec<Option<bool>>> = vec![vec![None; m + 1]; n + 1];
        Self::is_match_dp(n, m, &mut memo, &s, &p)
    }

    fn is_match_dp(
        n: usize,
        m: usize,
        memo: &mut Vec<Vec<Option<bool>>>,
        s: &[char],
        p: &[char],
    ) -> bool {
        if let Some(ans) = memo[n][m] {
            ans
        } else {
            let res = if n == 0 && m == 0 {
                true
            } else if n != 0 && m == 0 {
                false
            } else if n == 0 && m != 0 {
                if p[m - 1] == '*' {
                    Self::is_match_dp(n, m - 2, memo, s, p)
                } else {
                    false
                }
            } else {
                if s[n - 1] == p[m - 1] {
                    Self::is_match_dp(n - 1, m - 1, memo, s, p)
                } else {
                    match p[m - 1] {
                        '*' => match p[m - 2] {
                            '*' => false,
                            '.' => {
                                Self::is_match_dp(n - 1, m, memo, s, p)
                                    || Self::is_match_dp(n, m - 2, memo, s, p)
                            }
                            _ => {
                                if s[n - 1] != p[m - 2] {
                                    Self::is_match_dp(n, m - 2, memo, s, p)
                                } else {
                                    Self::is_match_dp(n - 1, m, memo, s, p)
                                        || Self::is_match_dp(n, m - 2, memo, s, p)
                                }
                            }
                        },
                        '.' => Self::is_match_dp(n - 1, m - 1, memo, s, p),
                        _ => false,
                    }
                }
            };
            memo[n][m] = Some(res);
            res
        }
    }
}
// @lc code=end

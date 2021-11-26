/*
 * @lc app=leetcode id=520 lang=rust
 *
 * [520] Detect Capital
 *
 * https://leetcode.com/problems/detect-capital/description/
 *
 * algorithms
 * Easy (54.23%)
 * Likes:    954
 * Dislikes: 312
 * Total Accepted:    206.9K
 * Total Submissions: 381.3K
 * Testcase Example:  '"USA"'
 *
 * We define the usage of capitals in a word to be right when one of the
 * following cases holds:
 *
 *
 * All letters in this word are capitals, like "USA".
 * All letters in this word are not capitals, like "leetcode".
 * Only the first letter in this word is capital, like "Google".
 *
 *
 * Given a string word, return true if the usage of capitals in it is right.
 *
 *
 * Example 1:
 * Input: word = "USA"
 * Output: true
 * Example 2:
 * Input: word = "FlaG"
 * Output: false
 *
 *
 * Constraints:
 *
 *
 * 1 <= word.length <= 100
 * word consists of lowercase and uppercase English letters.
 *
 *
 */
struct Solution;
// @lc code=start
impl Solution {
    pub fn detect_capital_use(word: String) -> bool {
        let mut word = word.chars();
        let first = word.next();
        if first.is_none() {
            return true;
        }
        let first = first.unwrap();

        if let Some(second) = word.next() {
            let res = word.try_for_each(move |x| {
                if second.is_lowercase() && x.is_lowercase() {
                    return Ok(());
                }

                if second.is_uppercase() && x.is_uppercase() {
                    return Ok(());
                }

                Err(())
            });

            if res.is_err() {
                return false;
            }
            if first.is_uppercase() {
                return true;
            }

            if first.is_lowercase() && second.is_lowercase() {
                return true;
            }

            false
        } else {
            true
        }
    }
}
// @lc code=end

/*
 * @lc app=leetcode id=1502 lang=rust
 *
 * [1502] Can Make Arithmetic Progression From Sequence
 *
 * https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/description/
 *
 * algorithms
 * Easy (70.26%)
 * Likes:    687
 * Dislikes: 45
 * Total Accepted:    84.1K
 * Total Submissions: 121K
 * Testcase Example:  '[3,5,1]'
 *
 * A sequence of numbers is called an arithmetic progression if the difference
 * between any two consecutive elements is the same.
 *
 * Given an array of numbers arr, return true if the array can be rearranged to
 * form an arithmetic progression. Otherwise, return false.
 *
 *
 * Example 1:
 *
 *
 * Input: arr = [3,5,1]
 * Output: true
 * Explanation: We can reorder the elements as [1,3,5] or [5,3,1] with
 * differences 2 and -2 respectively, between each consecutive elements.
 *
 *
 * Example 2:
 *
 *
 * Input: arr = [1,2,4]
 * Output: false
 * Explanation: There is no way to reorder the elements to obtain an arithmetic
 * progression.
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= arr.length <= 1000
 * -10^6 <= arr[i] <= 10^6
 *
 *
 */

struct Solution;

// @lc code=start
impl Solution {
    pub fn can_make_arithmetic_progression(mut arr: Vec<i32>) -> bool {
        arr.sort_unstable();
        let diff: Vec<i32> = arr.windows(2).map(|v| v[1] - v[0]).collect();
        diff.iter().min() == diff.iter().max()
    }
}
// @lc code=end

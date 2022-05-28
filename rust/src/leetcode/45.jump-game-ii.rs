/*
 * @lc app=leetcode id=45 lang=rust
 *
 * [45] Jump Game II
 *
 * https://leetcode.com/problems/jump-game-ii/description/
 *
 * algorithms
 * Medium (35.23%)
 * Likes:    6328
 * Dislikes: 240
 * Total Accepted:    480.5K
 * Total Submissions: 1.4M
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * Given an array of non-negative integers nums, you are initially positioned
 * at the first index of the array.
 *
 * Each element in the array represents your maximum jump length at that
 * position.
 *
 * Your goal is to reach the last index in the minimum number of jumps.
 *
 * You can assume that you can always reach the last index.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [2,3,1,1,4]
 * Output: 2
 * Explanation: The minimum number of jumps to reach the last index is 2. Jump
 * 1 step from index 0 to 1, then 3 steps to the last index.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [2,3,0,1,4]
 * Output: 2
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^4
 * 0 <= nums[i] <= 1000
 *
 *
 */

// @lc code=start
impl Solution {
    pub fn jump(nums: Vec<i32>) -> i32 {
        let mut cur = 0;
        let mut res = 0;
        let mut i = 0;
        let n = nums.len();
        while cur < n - 1 {
            res += 1;
            let pre = cur;
            while i <= pre {
                cur = cur.max(i + nums[i] as usize);
                i += 1;
            }
        }
        res

    }
}
// @lc code=end

struct Solution;

#[cfg(test)]
#[test]
fn test_() {
    todo!()
}

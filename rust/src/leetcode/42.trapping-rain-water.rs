/*
 * @lc app=leetcode id=42 lang=rust
 *
 * [42] Trapping Rain Water
 *
 * https://leetcode.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (54.39%)
 * Likes:    18600
 * Dislikes: 262
 * Total Accepted:    1.1M
 * Total Submissions: 2M
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * Given n non-negative integers representing an elevation map where the width
 * of each bar is 1, compute how much water it can trap after raining.
 *
 *
 * Example 1:
 *
 *
 * Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 * Explanation: The above elevation map (black section) is represented by array
 * [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue
 * section) are being trapped.
 *
 *
 * Example 2:
 *
 *
 * Input: height = [4,2,0,3,2,5]
 * Output: 9
 *
 *
 *
 * Constraints:
 *
 *
 * n == height.length
 * 1 <= n <= 2 * 10^4
 * 0 <= height[i] <= 10^5
 *
 *
 */
struct Solution;
// @lc code=start
impl Solution {
    pub fn trap(height: Vec<i32>) -> i32 {
        let n = height.len();
        if n == 0 {
            return 0;
        }
        let mut l = 0;
        let mut r = n - 1;
        let mut level = 0;
        let mut res = 0;

        while l < r {
            let lower = if height[l] < height[r] {
                let lower = height[l];
                l += 1;
                lower
            } else {
                let lower = height[r];
                r -= 1;
                lower
            };
            level = level.max(lower);
            res += level - lower;
        }
        res
    }
}
// @lc code=end

/*
 * @lc app=leetcode id=41 lang=rust
 *
 * [41] First Missing Positive
 *
 * https://leetcode.com/problems/first-missing-positive/description/
 *
 * algorithms
 * Hard (33.15%)
 * Likes:    4810
 * Dislikes: 905
 * Total Accepted:    419K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,2,0]'
 *
 * Given an unsorted integer array nums, find the smallest missing positive
 * integer.
 * 
 * Follow up: Could you implement an algorithm that runs in O(n) time and uses
 * constant extra space.?
 * 
 * 
 * Example 1:
 * Input: nums = [1,2,0]
 * Output: 3
 * Example 2:
 * Input: nums = [3,4,-1,1]
 * Output: 2
 * Example 3:
 * Input: nums = [7,8,9,11,12]
 * Output: 1
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= nums.length <= 300
 * -2^31 <= nums[i] <= 2^31 - 1
 * 
 * 
 */

// @lc code=start
impl Solution {
    pub fn first_missing_positive(nums: Vec<i32>) -> i32 {
        let mut nums = nums;
        let l = nums.len() as i32;
        for i in 0..nums.len() {
            // n = nums[i] 搬到 nums[n-1]
            let mut n = nums[i];
            while n > 0 && n <= l && nums[(n-1) as usize] != n {
                std::mem::swap(&mut nums[(n-1) as usize], &mut n);
            }
        }

        for i in 0..l {
            if nums[i as usize] != i + 1 {
                return i + 1;
            }
        }
        l + 1
    }
}
// @lc code=end

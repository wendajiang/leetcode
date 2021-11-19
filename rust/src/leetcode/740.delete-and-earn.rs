/*
 * @lc app=leetcode id=740 lang=rust
 *
 * [740] Delete and Earn
 *
 * https://leetcode.com/problems/delete-and-earn/description/
 *
 * algorithms
 * Medium (53.71%)
 * Likes:    2656
 * Dislikes: 178
 * Total Accepted:    93.8K
 * Total Submissions: 174.4K
 * Testcase Example:  '[3,4,2]'
 *
 * You are given an integer array nums. You want to maximize the number of
 * points you get by performing the following operation any number of
 * times:
 * 
 * 
 * Pick any nums[i] and delete it to earn nums[i] points. Afterwards, you must
 * delete every element equal to nums[i] - 1 and every element equal to nums[i]
 * + 1.
 * 
 * 
 * Return the maximum number of points you can earn by applying the above
 * operation some number of times.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [3,4,2]
 * Output: 6
 * Explanation: You can perform the following operations:
 * - Delete 4 to earn 4 points. Consequently, 3 is also deleted. nums = [2].
 * - Delete 2 to earn 2 points. nums = [].
 * You earn a total of 6 points.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [2,2,3,3,3,4]
 * Output: 9
 * Explanation: You can perform the following operations:
 * - Delete a 3 to earn 3 points. All 2's and 4's are also deleted. nums =
 * [3,3].
 * - Delete a 3 again to earn 3 points. nums = [3].
 * - Delete a 3 once more to earn 3 points. nums = [].
 * You earn a total of 9 points.
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 2 * 10^4
 * 1 <= nums[i] <= 10^4
 * 
 * 
 */
// @lc code=start
impl Solution {
    pub fn delete_and_earn(nums: Vec<i32>) -> i32 {
        let mut dp = [0; 10001];
        for num in nums {
            dp[num as usize] += num;
        }
        let mut res = 0;
        for i in 1..=10000 {
            dp[i] = dp[i - 1].max(dp[i] + res);
            res = res.max(dp[i - 1]);
        }
        res.max(dp[10000])
    }
}
// @lc code=end

struct Solution;

#[test]
fn test() {
    assert_eq!(Solution::delete_and_earn(vec![2,2,3,3,3,4]), 9);
    assert_eq!(Solution::delete_and_earn(vec![3,4,2]), 6);
}
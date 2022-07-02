/*
 * @lc app=leetcode id=2235 lang=cpp
 *
 * [2235] Add Two Integers
 *
 * https://leetcode.com/problems/add-two-integers/description/
 *
 * algorithms
 * Easy (92.32%)
 * Likes:    267
 * Dislikes: 986
 * Total Accepted:    52.5K
 * Total Submissions: 56.9K
 * Testcase Example:  '12\n5'
 *
 * Given two integers num1 and num2, return the sum of the two integers.
 *
 * Example 1:
 *
 *
 * Input: num1 = 12, num2 = 5
 * Output: 17
 * Explanation: num1 is 12, num2 is 5, and their sum is 12 + 5 = 17, so 17 is
 * returned.
 *
 *
 * Example 2:
 *
 *
 * Input: num1 = -10, num2 = 4
 * Output: -6
 * Explanation: num1 + num2 = -6, so -6 is returned.
 *
 *
 *
 * Constraints:
 *
 *
 * -100 <= num1, num2 <= 100
 *
 *
 */

// @lc code=start
class Solution {
   public:
    int sum(int num1, int num2) { return num1 + num2; }
};
// @lc code=end

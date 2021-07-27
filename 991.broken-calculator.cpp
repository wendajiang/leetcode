/*
 * @lc app=leetcode id=991 lang=cpp
 *
 * [991] Broken Calculator
 *
 * https://leetcode.com/problems/broken-calculator/description/
 *
 * algorithms
 * Medium (46.31%)
 * Likes:    941
 * Dislikes: 138
 * Total Accepted:    44K
 * Total Submissions: 88.4K
 * Testcase Example:  '2\n3'
 *
 * On a broken calculator that has a number showing on its display, we can
 * perform two operations:
 *
 *
 * Double: Multiply the number on the display by 2, or;
 * Decrement: Subtract 1 from the number on the display.
 *
 *
 * Initially, the calculator is displaying the number x.
 *
 * Return the minimum number of operations needed to display the number y.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: x = 2, y = 3
 * Output: 2
 * Explanation: Use double operation and then decrement operation {2 -> 4 ->
 * 3}.
 *
 *
 * Example 2:
 *
 *
 * Input: x = 5, y = 8
 * Output: 2
 * Explanation: Use decrement and then double {5 -> 4 -> 8}.
 *
 *
 * Example 3:
 *
 *
 * Input: x = 3, y = 10
 * Output: 3
 * Explanation:  Use double, decrement and double {3 -> 6 -> 5 -> 10}.
 *
 *
 * Example 4:
 *
 *
 * Input: x = 1024, y = 1
 * Output: 1023
 * Explanation: Use decrement operations 1023 times.
 *
 *
 *
 *
 * Note:
 *
 *
 * 1 <= x <= 10^9
 * 1 <= y <= 10^9
 *
 *
 */

// @lc code=start
class Solution {
public:
    int brokenCalc(int x, int y) {
         if (y <= x) return x - y;
         else return 1 + brokenCalc(x, y % 2 ? y + 1 : y / 2);
    }
};
// @lc code=end

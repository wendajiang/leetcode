/*
 * @lc app=leetcode id=556 lang=cpp
 *
 * [556] Next Greater Element III
 *
 * https://leetcode.com/problems/next-greater-element-iii/description/
 *
 * algorithms
 * Medium (33.40%)
 * Likes:    1502
 * Dislikes: 282
 * Total Accepted:    75.2K
 * Total Submissions: 225.2K
 * Testcase Example:  '12'
 *
 * Given a positive integer n, find the smallest integer which has exactly the
 * same digits existing in the integer n and is greater in value than n. If no
 * such positive integer exists, return -1.
 *
 * Note that the returned integer should fit in 32-bit integer, if there is a
 * valid answer but it does not fit in 32-bit integer, return -1.
 *
 *
 * Example 1:
 * Input: n = 12
 * Output: 21
 * Example 2:
 * Input: n = 21
 * Output: -1
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 2^31 - 1
 *
 *
 */

// @lc code=start
// https://www.cnblogs.com/grandyang/p/6716130.html
class Solution {
public:
    int nextGreaterElement(int n) {
        string str = to_string(n);
        int len = str.size(), i = len - 1;
        for (; i > 0; i--) {
            if (str[i] > str[i - 1]) break;
        }

        if (i == 0) return -1;
        for (int j = len - 1; j >= i; j--) {
            if (str[j] > str[i - 1]) {
                swap(str[j], str[i - 1]);
                break;
            }
        }
        sort(str.begin() + i, str.end());
        long long res = stoll(str);
        return res > numeric_limits<int>::max() ? -1 : res;
    }

    // int nextGreaterElement(int n) {
        // string str = to_string(n);
        // next_permutation(str.begin(), str.end());
        // long long res = stoll(str);
        // return (res > INT_MAX || res <= n) ? -1 : res;
    // }
};
// @lc code=end

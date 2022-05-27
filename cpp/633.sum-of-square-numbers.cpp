/*
 * [633] Sum of Square Numbers
 *
 * https://leetcode.com/problems/sum-of-square-numbers
 *
 * Easy (31.43%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '5'
 *
 *
 * Given a non-negative integer c, your task is to decide whether there're two
 * integers a and b such that a2 + b2 = c.
 *
 *
 * Example 1:
 *
 * Input: 5
 * Output: True
 * Explanation: 1 * 1 + 2 * 2 = 5
 *
 *
 *
 *
 * Example 2:
 *
 * Input: 3
 * Output: False
 *
 *
 *
 */
class Solution {
public:
    bool judgeSquareSum(int c) {
        int l = 0;
        int r = std::sqrt(c);
        while(l <= r){
            long cur = l * l + r * r;
            if(cur < c)
                l++;
            else if(cur > c)
                r--;
            else
                return true;
        }
        return false;
    }
};

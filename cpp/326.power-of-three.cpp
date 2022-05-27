/*
 * [326] Power of Three
 *
 * https://leetcode.com/problems/power-of-three
 *
 * Easy (40.12%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '27'
 *
 *
 * ⁠   Given an integer, write a function to determine if it is a power of
 * three.
 *
 *
 * ⁠   Follow up:
 * ⁠   Could you do it without using any loop / recursion?
 *
 *
 * Credits:Special thanks to @dietpepsi for adding this problem and creating
 * all test cases.
 */
class Solution {
public:
    bool isPowerOfThree(int n) {
        // return fmod(log10(n)/log10(3), 1) == 0;
        return ( n > 0 &&  1162261467 % n == 0);  //这两种方法差不多
    }
};

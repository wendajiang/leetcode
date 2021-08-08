/*
 * @lc app=leetcode id=224 lang=cpp
 *
 * [224] Basic Calculator
 *
 * https://leetcode.com/problems/basic-calculator/description/
 *
 * algorithms
 * Hard (37.93%)
 * Likes:    2473
 * Dislikes: 222
 * Total Accepted:    224K
 * Total Submissions: 577.3K
 * Testcase Example:  '"1 + 1"'
 *
 * Given a string s representing a valid expression, implement a basic
 * calculator to evaluate it, and return the result of the evaluation.
 *
 * Note: You are not allowed to use any built-in function which evaluates
 * strings as mathematical expressions, such as eval().
 *
 *
 * Example 1:
 *
 *
 * Input: s = "1 + 1"
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: s = " 2-1 + 2 "
 * Output: 3
 *
 *
 * Example 3:
 *
 *
 * Input: s = "(1+(4+5+2)-3)+(6+8)"
 * Output: 23
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 3 * 10^5
 * s consists of digits, '+', '-', '(', ')', and ' '.
 * s represents a valid expression.
 * '+' is not used as a unary operation.
 * '-' could be used as a unary operation but it has to be followed by
 * parentheses.
 * Every number and running calculation will fit in a signed 32-bit integer.
 *
 *
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    int calculate(string s) {
        function<int(int&)> eval = [&](int &pos) {
            int ret = 0;
            int sign = 1;
            int val = 0;
            while (pos < s.size()) {
                const char ch = s[pos];
                if (isdigit(ch)) {
                    val = val * 10 + (s[pos++] - '0');
                } else if (ch == '+' || ch == '-') {
                    ret += sign * val;
                    val = 0;
                    sign = ch == '+' ? 1 : -1;
                    ++pos;
                } else if (ch == '(') {
                    val = eval(++pos);
                } else if (ch == ')') {
                    ++pos;
                    break;
                } else {
                    ++pos;
                }
            }
            return ret += sign * val;
        };
        int pos = 0;
        return eval(pos);
    }
};
// @lc code=end

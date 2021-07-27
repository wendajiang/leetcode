/*
 * @lc app=leetcode id=227 lang=cpp
 *
 * [227] Basic Calculator II
 *
 * https://leetcode.com/problems/basic-calculator-ii/description/
 *
 * algorithms
 * Medium (38.23%)
 * Likes:    2632
 * Dislikes: 397
 * Total Accepted:    289.5K
 * Total Submissions: 735.8K
 * Testcase Example:  '"3+2*2"'
 *
 * Given a string s which represents an expression, evaluate this expression
 * and return its value. 
 *
 * The integer division should truncate toward zero.
 *
 * Note: You are not allowed to use any built-in function which evaluates
 * strings as mathematical expressions, such as eval().
 *
 *
 * Example 1:
 * Input: s = "3+2*2"
 * Output: 7
 * Example 2:
 * Input: s = " 3/2 "
 * Output: 1
 * Example 3:
 * Input: s = " 3+5 / 2 "
 * Output: 5
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 3 * 10^5
 * s consists of integers and operators ('+', '-', '*', '/') separated by some
 * number of spaces.
 * s represents a valid expression.
 * All the integers in the expression are non-negative integers in the range
 * [0, 2^31 - 1].
 * The answer is guaranteed to fit in a 32-bit integer.
 *
 *
 */
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
   public:
    int calculate(string s) {
        vector<int> nums;
        char op = '+';
        int cur = 0;
        int pos = 0;
        while(pos < s.size()) {
            if (s[pos] == ' ') {
                pos++;
                continue;
            }
            while(isdigit(s[pos]) && pos < s.size()) {
                cur = cur * 10 + (s[pos++] - '0');
            }
            if (op == '+' || op == '-') {
                nums.push_back(cur * (op == '-' ? -1 : 1));
            } else if (op == '/') {
                nums.back() /= cur;
            } else if (op == '*') {
                nums.back() *= cur;
            }
            cur = 0;
            op = s[pos++];
        }
        return accumulate(begin(nums), end(nums), 0);
    }
};
// @lc code=end

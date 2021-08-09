/*
 * @lc app=leetcode id=678 lang=cpp
 *
 * [678] Valid Parenthesis String
 *
 * https://leetcode.com/problems/valid-parenthesis-string/description/
 *
 * algorithms
 * Medium (31.47%)
 * Likes:    2386
 * Dislikes: 68
 * Total Accepted:    133.8K
 * Total Submissions: 420.4K
 * Testcase Example:  '"()"'
 *
 * Given a string s containing only three types of characters: '(', ')' and
 * '*', return true if s is valid.
 *
 * The following rules define a valid string:
 *
 *
 * Any left parenthesis '(' must have a corresponding right parenthesis
 * ')'.
 * Any right parenthesis ')' must have a corresponding left parenthesis
 * '('.
 * Left parenthesis '(' must go before the corresponding right parenthesis
 * ')'.
 * '*' could be treated as a single right parenthesis ')' or a single left
 * parenthesis '(' or an empty string "".
 *
 *
 *
 * Example 1:
 * Input: s = "()"
 * Output: true
 * Example 2:
 * Input: s = "(*)"
 * Output: true
 * Example 3:
 * Input: s = "(*))"
 * Output: true
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 100
 * s[i] is '(', ')' or '*'.
 *
 *
 */
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    bool checkValidString(string s) {
        stack<char> left;
        stack<char> star;
        for (auto i = 0; i < s.size(); i++) {
            switch(s[i]) {
            case '(':
                left.push(i);
                break;
            case '*':
                star.push(i);
                break;
            case ')':
                if (left.size() > 0) left.pop();
                else if (star.size() > 0) star.pop();
                else return false;
                break;
            }
        }

        while(left.size() > 0 && star.size() > 0) {
            if (left.top() < star.top()) {
                left.pop(); star.pop();
            } else {
                return false;
            }
        }

        return (left.size() == 0 || (left.size() == star.size()));
    }

};
// @lc code=end

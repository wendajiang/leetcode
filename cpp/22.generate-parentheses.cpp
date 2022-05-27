/*
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses
 *
 * algorithms
 * Medium (44.80%)
 * Total Accepted:    157.3K
 * Total Submissions: 349.5K
 * Testcase Example:  '3'
 *
 *
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 *
 *
 *
 * For example, given n = 3, a solution set is:
 *
 *
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 *
 */
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs("", res, n, n);
        return res;
    }
    void dfs(string solution, vector<string>& res, int countleft, int countright){
        if(countleft == 0 && countright == 0){
            res.push_back(solution);
            return ;
        }
        if(countleft > 0) {
            dfs(solution + "(", res, countleft - 1, countright);
        }
        if(countright > countleft) {
            dfs(solution + ")", res, countleft, countright - 1);
        }
    }
};

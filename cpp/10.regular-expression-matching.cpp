/*
 * [10] Regular Expression Matching
 *
 * https://leetcode.com/problems/regular-expression-matching
 *
 * Hard (24.04%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '"aa"\n"a"'
 *
 * Implement regular expression matching with support for '.' and '*'.
 *
 *
 * '.' Matches any single character.
 * '*' Matches zero or more of the preceding element.
 *
 * The matching should cover the entire input string (not partial).
 *
 * The function prototype should be:
 * bool isMatch(const char *s, const char *p)
 *
 * Some examples:
 * isMatch("aa","a") ? false
 * isMatch("aa","aa") ? true
 * isMatch("aaa","aa") ? false
 * isMatch("aa", "a*") ? true
 * isMatch("aa", ".*") ? true
 * isMatch("ab", ".*") ? true
 * isMatch("aab", "c*a*b") ? true
 *
 */

#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    // DP解法
    /*
    This problem has a typical solution using Dynamic Programming. We define the
    state P[i][j] to be true if s[0..i) matches p[0..j) and false otherwise.
    Then the state equations are:

    P[i][j] = P[i - 1][j - 1], if p[j - 1] != '*' && (s[i - 1] == p[j - 1] ||
    p[j - 1] == '.'); P[i][j] = P[i][j - 2], if p[j - 1] == '*' and the pattern
    repeats for 0 times; P[i][j] = P[i - 1][j] && (s[i - 1] == p[j - 2] || p[j -
    2] == '.'), if p[j - 1] == '*' and the pattern repeats for at least 1 times.

    Putting these together, we will have the following code.
    */
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        vector<vector<bool> > dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] == '*')
                    dp[i][j] = dp[i][j - 2] ||
                               (i > 0 && dp[i - 1][j] &&
                                (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
                else
                    dp[i][j] = i > 0 && dp[i - 1][j - 1] &&
                               (s[i - 1] == p[j - 1] || p[j - 1] == '.');
            }
        }
        return dp[m][n];
    }

    // //
    // 在ide中测试没有问题，递归方法栈深度过深是可能存在的问题，上面使用DP解法
    // bool isMatch(string s, string p) {
    //     if(s.size() == 0 || p.size() == 0)
    //         return false;
    //     return isMatchCore(s, p, 0, 0);
    // }
    // bool isMatchCore(string s, string p, int si, int pi){
    //     if(si == s.size() && pi == p.size())
    //         return true;
    //     if(si != s.size() && pi == p.size())
    //         return false;
    //     if(pi + 1 < p.size() && p[pi + 1] == '*'){
    //         if(s[si] == p[pi] || (p[pi] == '.' && s[si] != s.size())){
    //             return isMatchCore(s, p, si + 1, pi + 2)
    //                 || isMatchCore(s, p, si + 1, pi)
    //                 || isMatchCore(s, p, si, pi + 2);
    //         }else
    //             return isMatchCore(s, p, si, pi + 2);
    //     }
    //     if(s[si] == p[pi] || (p[pi] == '.' && s[si] != s.size()))
    //         return isMatchCore(s, p, si + 1, pi + 1);
    //     return false;
    // }
};

/*
 * @lc app=leetcode id=1349 lang=cpp
 *
 * [1349] Maximum Students Taking Exam
 *
 * https://leetcode.com/problems/maximum-students-taking-exam/description/
 *
 * algorithms
 * Hard (43.28%)
 * Likes:    348
 * Dislikes: 9
 * Total Accepted:    6.6K
 * Total Submissions: 15.3K
 * Testcase Example:  '[["#",".","#","#",".","#"],[".","#","#","#","#","."],["#",".","#","#",".","#"]]'
 *
 * Given a m * n matrix seats  that represent seats distributions in a
 * classroom. If a seat is broken, it is denoted by '#' character otherwise it
 * is denoted by a '.' character.
 * 
 * Students can see the answers of those sitting next to the left, right, upper
 * left and upper right, but he cannot see the answers of the student sitting
 * directly in front or behind him. Return the maximum number of students that
 * can take the exam together without any cheating being possible..
 * 
 * Students must be placed in seats in good condition.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: seats = [["#",".","#","#",".","#"],
 * [".","#","#","#","#","."],
 * ["#",".","#","#",".","#"]]
 * Output: 4
 * Explanation: Teacher can place 4 students in available seats so they don't
 * cheat on the exam. 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: seats = [[".","#"],
 * ["#","#"],
 * ["#","."],
 * ["#","#"],
 * [".","#"]]
 * Output: 3
 * Explanation: Place all students in available seats. 
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: seats = [["#",".",".",".","#"],
 * [".","#",".","#","."],
 * [".",".","#",".","."],
 * [".","#",".","#","."],
 * ["#",".",".",".","#"]]
 * Output: 10
 * Explanation: Place students in available seats in column 1, 3 and 5.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * seats contains only characters '.' and'#'.
 * m == seats.length
 * n == seats[i].length
 * 1 <= m <= 8
 * 1 <= n <= 8
 * 
 * 
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int popcount (unsigned u)
    {
        u = (u & 0x55555555) + ((u >> 1) & 0x55555555);
        u = (u & 0x33333333) + ((u >> 2) & 0x33333333);
        u = (u & 0x0F0F0F0F) + ((u >> 4) & 0x0F0F0F0F);
        u = (u & 0x00FF00FF) + ((u >> 8) & 0x00FF00FF);
        u = (u & 0x0000FFFF) + ((u >> 16) & 0x0000FFFF);
        return u;
    }
    int maxStudents(vector<vector<char>>& seats) {
        const int m = seats.size();
        if (m == 0) return 0;
        const int n = seats[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(1 << n, 0));
        vector<int> s(m + 1, 0);

        for (int i = 1; i <= m; i++) {
            for (int j = 0; j < n; j++) {
                s[i] |= ((seats[i - 1][j] == '#') << j);
            }
        }

        for (int i = 1; i <= m; i++) {
            for (int c = 0; c < (1 << n); c++) {
                if (c & (c >> 1) || c & (s[i])) continue;
                for (int l = 0; l < (1 << n); l++) {
                    if (!(l & s[i - 1]) && !(l & (c >> 1)) && !((l >> 1) & c)) {
                        dp[i][c] = max(dp[i][c], dp[i - 1][l] + popcount(c));
                    }
                }
            }
        }
        return *max_element(begin(dp[m]), end(dp[m]));
    }
};
// @lc code=end


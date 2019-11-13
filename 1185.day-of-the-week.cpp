/*
 * @lc app=leetcode id=1185 lang=cpp
 *
 * [1185] Day of the Week
 *
 * https://leetcode.com/problems/day-of-the-week/description/
 *
 * algorithms
 * Easy (64.42%)
 * Likes:    30
 * Dislikes: 474
 * Total Accepted:    10.2K
 * Total Submissions: 15.9K
 * Testcase Example:  '31\n8\n2019'
 *
 * Given a date, return the corresponding day of the week for that date.
 * 
 * The input is given as three integers representing the day, month and year
 * respectively.
 * 
 * Return the answer as one of the following values {"Sunday", "Monday",
 * "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: day = 31, month = 8, year = 2019
 * Output: "Saturday"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: day = 18, month = 7, year = 1999
 * Output: "Sunday"
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: day = 15, month = 8, year = 1993
 * Output: "Sunday"
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The given dates are valid dates between the years 1971 and 2100.
 * 
 */

#include <bits/stdc++.h>

// @lc code=start
class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        char WEEK[][10] = {
            {"Monday"},
            {"Tuesday"},
            {"Wednesday"},
            {"Thursday"},
            {"Friday"},
            {"Saturday"},
            {"Sunday"}
        };
        int w = 7;
        if (month == 1 || month == 2) {
            month += 12;
            year--;
        }
        //?????????
        w = (day + 2 * month + 3 * (month + 1) / 5 + year + year / 4 - year / 100 + year / 400) %7;
        return string(WEEK[w]);
    }
};
// @lc code=end


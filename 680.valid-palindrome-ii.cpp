/*
 * @lc app=leetcode id=680 lang=cpp
 *
 * [680] Valid Palindrome II
 *
 * https://leetcode.com/problems/valid-palindrome-ii/description/
 *
 * algorithms
 * Easy (37.00%)
 * Likes:    3026
 * Dislikes: 187
 * Total Accepted:    299.6K
 * Total Submissions: 798.5K
 * Testcase Example:  '"aba"'
 *
 * Given a string s, return true if the s can be palindrome after deleting at
 * most one character from it.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "aba"
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: s = "abca"
 * Output: true
 * Explanation: You could delete the character 'c'.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "abc"
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^5
 * s consists of lowercase English letters.
 *
 *
 */

// @lc code=start
class Solution {
public:
    bool validPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while(l <= r && s[l] == s[r]) {
            l++; r--;
        }

        if (l >= r)
            return true;
        else {
            return isPalindrome(s, l + 1, r) || isPalindrome(s, l, r - 1);
        }
    }

private:
    bool isPalindrome(string &s, int l, int r) {
        while(l <= r && s[l] == s[r]) {
            l++; r--;
        }
        if (l >= r) return true;
        else return false;
    }
};
// @lc code=end

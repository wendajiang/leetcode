/*
 * [459] Repeated Substring Pattern
 *
 * https://leetcode.com/problems/repeated-substring-pattern
 *
 * Easy (38.12%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '"abab"'
 *
 * Given a non-empty string check if it can be constructed by taking a
 * substring of it and appending multiple copies of the substring together.
 * You may assume the given string consists of lowercase English letters only
 * and its length  will not exceed 10000.
 *
 * Example 1:
 *
 * Input: "abab"
 *
 * Output: True
 *
 * Explanation: It's the substring "ab" twice.
 *
 *
 *
 * Example 2:
 *
 * Input: "aba"
 *
 * Output: False
 *
 *
 *
 * Example 3:
 *
 * Input: "abcabcabcabc"
 *
 * Output: True
 *
 * Explanation: It's the substring "abc" four times. (And the substring
 * "abcabc" twice.)
 *
 *
 */
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int j = 1;
        int k = 0;
        int len = s.size();
        vector<int> pi(len + 1, 0);
        while(j < len){
            if(s[j] == s[k]) pi[++j] = ++k;
            else if(k == 0) j++;
            else k = pi[k];
        }
        return pi[len] && len % (len - pi[len]) == 0;
    }
};

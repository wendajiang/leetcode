/*
 * [647] Palindromic Substrings
 *
 * https://leetcode.com/problems/palindromic-substrings/description/
 *
 * algorithms
 * Medium (55.01%)
 * Total Accepted:    34.3K
 * Total Submissions: 62.4K
 * Testcase Example:  '"abc"'
 *
 * 
 * Given a string, your task is to count how many palindromic substrings in
 * this string.
 * 
 * 
 * 
 * The substrings with different start indexes or end indexes are counted as
 * different substrings even they consist of same characters. 
 * 
 * 
 * Example 1:
 * 
 * Input: "abc"
 * Output: 3
 * Explanation: Three palindromic strings: "a", "b", "c".
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: "aaa"
 * Output: 6
 * Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 * 
 * 
 * 
 * Note:
 * 
 * The input string length won't exceed 1000.
 * 
 * 
 */
class Solution {
public:
    int cnt = 0;
    int countSubstrings(string s) {
        for(int i = 0; i < s.size(); i++){
            extendSubstrings(s, i, i); //奇数
            extendSubstrings(s, i, i + 1); //偶数
        }
        return cnt;
    }
    void extendSubstrings(string s, int start, int end){
        while(start >= 0 && end < s.size() && s[start] == s[end]){
            start--;
            end++;
            cnt++;
        }
    }
};

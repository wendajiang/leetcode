/*
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring
 *
 * Medium (25.14%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '"babad"'
 *
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 *
 * Example:
 *
 * Input: "babad"
 *
 * Output: "bab"
 *
 * Note: "aba" is also a valid answer.
 *
 *
 *
 * Example:
 *
 * Input: "cbbd"
 *
 * Output: "bb"
 *
 *
 */
class Solution {
public:
    string longestPalindrome(string s) {
        int P[s.size()][s.size()];
        memset(P, 0 , s.size()*s.size()*sizeof(int));
        int maxL = 0, start = 0, end = 0;
        for(int i = 0; i < s.size(); i++){
            for(int j = i - 1; j >= 0; j--){
                P[j][i] = (s[j] == s[i] && (i - j < 2 || P[j + 1][i - 1]));
                if(P[j][i] && maxL < (i - j + 1)){
                    maxL = i - j + 1;
                    start = j;
                    end = i;
                }
            }
            P[i][i] = 1;
        }
        return s.substr(start, end - start + 1);
    }

};

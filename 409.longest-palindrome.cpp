/*
 * [409] Longest Palindrome
 *
 * https://leetcode.com/problems/longest-palindrome
 *
 * Easy (45.35%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '"abccccdd"'
 *
 * Given a string which consists of lowercase or uppercase letters, find the
 * length of the longest palindromes that can be built with those letters.
 *
 * This is case sensitive, for example "Aa" is not considered a palindrome
 * here.
 *
 * Note:
 * Assume the length of given string will not exceed 1,010.
 *
 *
 * Example:
 *
 * Input:
 * "abccccdd"
 *
 * Output:
 * 7
 *
 * Explanation:
 * One longest palindrome that can be built is "dccaccd", whose length is 7.
 *
 *
 */
class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> mp(256 + 1, 0);
        for(auto c : s){
            mp[c]++;
        }
        int longest = 0;
        bool flag = false;
        for(auto count : mp){
            if(count != 1 && (count & 1) != 0){
                longest += count - 1;
                flag = true;
            }else if(count == 1){
                flag = true;
            }else if((count & 1) == 0){
                longest += count;
            }
        }
        if(flag) longest += 1;
        return longest;
    }
};

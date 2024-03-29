/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 *
 * https://leetcode.com/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (60.28%)
 * Likes:    4975
 * Dislikes: 217
 * Total Accepted:    1.3M
 * Total Submissions: 2.1M
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * Given two strings s and t, return true if t is an anagram of s, and false
 * otherwise.
 *
 * An Anagram is a word or phrase formed by rearranging the letters of a
 * different word or phrase, typically using all the original letters exactly
 * once.
 *
 *
 * Example 1:
 * Input: s = "anagram", t = "nagaram"
 * Output: true
 * Example 2:
 * Input: s = "rat", t = "car"
 * Output: false
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length, t.length <= 5 * 10^4
 * s and t consist of lowercase English letters.
 *
 *
 *
 * Follow up: What if the inputs contain Unicode characters? How would you
 * adapt your solution to such a case?
 *
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
   public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        unordered_map<char, int> mps;
        unordered_map<char, int> mpt;
        for (int i = 0; i < s.size(); i++) {
            mps[s[i]]++;
            mpt[t[i]]++;
        }

        for (auto p : mps) {
            if (mpt[p.first] != p.second) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

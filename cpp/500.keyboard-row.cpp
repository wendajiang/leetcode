/*
 * @lc app=leetcode id=500 lang=cpp
 *
 * [500] Keyboard Row
 *
 * https://leetcode.com/problems/keyboard-row/description/
 *
 * algorithms
 * Easy (67.10%)
 * Likes:    928
 * Dislikes: 924
 * Total Accepted:    153K
 * Total Submissions: 224.5K
 * Testcase Example:  '["Hello","Alaska","Dad","Peace"]'
 *
 * Given an array of strings words, return the words that can be typed using
 * letters of the alphabet on only one row of American keyboard like the image
 * below.
 *
 * In the American keyboard:
 *
 *
 * the first row consists of the characters "qwertyuiop",
 * the second row consists of the characters "asdfghjkl", and
 * the third row consists of the characters "zxcvbnm".
 *
 *
 *
 * Example 1:
 *
 *
 * Input: words = ["Hello","Alaska","Dad","Peace"]
 * Output: ["Alaska","Dad"]
 *
 *
 * Example 2:
 *
 *
 * Input: words = ["omk"]
 * Output: []
 *
 *
 * Example 3:
 *
 *
 * Input: words = ["adsdf","sfd"]
 * Output: ["adsdf","sfd"]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= words.length <= 20
 * 1 <= words[i].length <= 100
 * words[i] consists of English letters (both lowercase and uppercase). 
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
   public:
    vector<string> findWords(vector<string>& words) {
        unordered_map<char, int> mp{
            {'q', 1}, {'w', 1}, {'e', 1}, {'r', 1}, {'t', 1}, {'y', 1},
            {'u', 1}, {'i', 1}, {'o', 1}, {'p', 1}, {'a', 2}, {'s', 2},
            {'d', 2}, {'f', 2}, {'g', 2}, {'h', 2}, {'j', 2}, {'k', 2},
            {'l', 2}, {'z', 3}, {'x', 3}, {'c', 3}, {'v', 3}, {'b', 3},
            {'n', 3}, {'m', 3}};
        vector<string> res;
        bool flag = true;
        for (int i = 0; i < words.size(); i++) {
            char c = std::tolower(words[i][0]);
            int tmp = mp[c];
            for (int j = 0; j < words[i].size(); j++) {
                char c1 = std::tolower(words[i][j]);
                if (mp[c1] != tmp) flag = false;
            }
            if (!flag) {
            } else {
                res.push_back(words[i]);
            }
            flag = true;
        }
        return res;
    }
};
// @lc code=end

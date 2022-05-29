/*
 * @lc app=leetcode id=318 lang=cpp
 *
 * [318] Maximum Product of Word Lengths
 *
 * https://leetcode.com/problems/maximum-product-of-word-lengths/description/
 *
 * algorithms
 * Medium (56.03%)
 * Likes:    2199
 * Dislikes: 101
 * Total Accepted:    159.1K
 * Total Submissions: 273.7K
 * Testcase Example:  '["abcw","baz","foo","bar","xtfn","abcdef"]'
 *
 * Given a string array words, return the maximum value of length(word[i]) *
 * length(word[j]) where the two words do not share common letters. If no such
 * two words exist, return 0.
 *
 *
 * Example 1:
 *
 *
 * Input: words = ["abcw","baz","foo","bar","xtfn","abcdef"]
 * Output: 16
 * Explanation: The two words can be "abcw", "xtfn".
 *
 *
 * Example 2:
 *
 *
 * Input: words = ["a","ab","abc","d","cd","bcd","abcd"]
 * Output: 4
 * Explanation: The two words can be "ab", "cd".
 *
 *
 * Example 3:
 *
 *
 * Input: words = ["a","aa","aaa","aaaa"]
 * Output: 0
 * Explanation: No such pair of words.
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= words.length <= 1000
 * 1 <= words[i].length <= 1000
 * words[i] consists only of lowercase English letters.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
   public:
    int maxProduct(vector<string>& words) {
        int res = 0;
        vector<uint32_t> word_mask;
        for (auto word : words) {
            uint32_t mask = 0;
            for (auto c : word) {
                mask |= (1 << (c - 'a'));
            }
            word_mask.push_back(mask);
        }
        for (int i = 0; i < words.size(); i++) {
            for (int j = i; j < words.size(); j++) {
                if ((word_mask[i] & word_mask[j]) == 0) {
                    res = max(res, (int)(words[i].size() * words[j].size()));
                }
            }
        }
        return res;
    }
};
// @lc code=end

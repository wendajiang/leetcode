/*
 * @lc app=leetcode id=720 lang=cpp
 *
 * [720] Longest Word in Dictionary
 *
 * https://leetcode.com/problems/longest-word-in-dictionary/description/
 *
 * algorithms
 * Easy (47.12%)
 * Likes:    532
 * Dislikes: 657
 * Total Accepted:    55.3K
 * Total Submissions: 116.3K
 * Testcase Example:  '["w","wo","wor","worl","world"]'
 *
 * Given a list of strings words representing an English Dictionary, find the
 * longest word in words that can be built one character at a time by other
 * words in words.  If there is more than one possible answer, return the
 * longest word with the smallest lexicographical order.  If there is no
 * answer, return the empty string.
 *
 * Example 1:
 *
 * Input:
 * words = ["w","wo","wor","worl", "world"]
 * Output: "world"
 * Explanation:
 * The word "world" can be built one character at a time by "w", "wo", "wor",
 * and "worl".
 *
 *
 *
 * Example 2:
 *
 * Input:
 * words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
 * Output: "apple"
 * Explanation:
 * Both "apply" and "apple" can be built from other words in the dictionary.
 * However, "apple" is lexicographically smaller than "apply".
 *
 *
 *
 * Note:
 * All the strings in the input will only contain lowercase letters.
 * The length of words will be in the range [1, 1000].
 * The length of words[i] will be in the range [1, 30].
 *
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    struct TrieNode {
        string str;
        TrieNode * next[26];

        TrieNode() {
            memset(next, 0, sizeof(next));
        }
    };


    void insert(TrieNode* root, string str) {
        TrieNode *cur = root;
        for (int i = 0; i < str.size(); i++) {
            char a = str[i];
            int index = a - 'a';
            if (nullptr == cur->next[index]) {
                cur->next[index] = new TrieNode();
            }
            cur = cur->next[index];
        }
        cur->str = str;
    }

    string longest;
    void dfs(TrieNode* node, int depth) {
        if (node == nullptr) {
            return;
        }
        if (depth >= longest.size() && node->str.size() == depth) {
            longest = node->str;
        }
        for (int i = 25; i >= 0; i--) {
            if (node->next[i] != nullptr && node->next[i]->str.size() > 0) {
                dfs(node->next[i], depth + 1);
            }
        }

    }
    string longestWord(vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (int i = 0; i < words.size(); i++) {
            insert(root, words[i]);
        }

        dfs(root, 0);

        return longest;

    }
};
// @lc code=end

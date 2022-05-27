/*
 * @lc app=leetcode id=648 lang=cpp
 *
 * [648] Replace Words
 *
 * https://leetcode.com/problems/replace-words/description/
 *
 * algorithms
 * Medium (57.81%)
 * Likes:    866
 * Dislikes: 139
 * Total Accepted:    64.3K
 * Total Submissions: 110.7K
 * Testcase Example:  '["cat","bat","rat"]\n"the cattle was rattled by the battery"'
 *
 * In English, we have a concept called root, which can be followed by some
 * other word to form another longer word - let's call this word successor. For
 * example, when the root "an" is followed by the successor word "other", we
 * can form a new word "another".
 * 
 * Given a dictionary consisting of many roots and a sentence consisting of
 * words separated by spaces, replace all the successors in the sentence with
 * the root forming it. If a successor can be replaced by more than one root,
 * replace it with the root that has the shortest length.
 * 
 * Return the sentence after the replacement.
 * 
 * 
 * Example 1:
 * Input: dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled
 * by the battery"
 * Output: "the cat was rat by the bat"
 * Example 2:
 * Input: dictionary = ["a","b","c"], sentence = "aadsfasf absbs bbab cadsfafs"
 * Output: "a a b c"
 * Example 3:
 * Input: dictionary = ["a", "aa", "aaa", "aaaa"], sentence = "a aa a aaaa aaa
 * aaa aaa aaaaaa bbb baba ababa"
 * Output: "a a a a a a a a bbb baba a"
 * Example 4:
 * Input: dictionary = ["catt","cat","bat","rat"], sentence = "the cattle was
 * rattled by the battery"
 * Output: "the cat was rat by the bat"
 * Example 5:
 * Input: dictionary = ["ac","ab"], sentence = "it is abnormal that this
 * solution is accepted"
 * Output: "it is ab that this solution is ac"
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= dictionary.length <= 1000
 * 1 <= dictionary[i].length <= 100
 * dictionary[i] consists of only lower-case letters.
 * 1 <= sentence.length <= 10^6
 * sentence consists of only lower-case letters and spaces.
 * The number of words in sentence is in the range [1, 1000]
 * The length of each word in sentence is in the range [1, 1000]
 * Each two consecutive words in sentence will be separated by exactly one
 * space.
 * sentence does not have leading or trailing spaces.
 * 
 * 
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
struct TrieNode {
    TrieNode *children[26];
    bool leaf;
    TrieNode() {
        leaf = false;
        fill_n(children, 26, nullptr);
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    ~Trie() {
        clear(root);
    }
    void insertWord(string& dict) {
        TrieNode *p = root;
        for (size_t i = 0; i < dict.size(); i++) {
            if (p->children[dict[i] - 'a'] == nullptr) p->children[dict[i] - 'a'] = new TrieNode();
            p = p->children[dict[i] - 'a'];
        }
        p->leaf = true;
    }
    bool searchWord(string& word, size_t &index) {
        TrieNode* p = root;
        for (size_t i = 0; i < word.size(); i++) {
            if (p->children[word[i] - 'a'] == nullptr) return false;
            if (p->children[word[i] - 'a']->leaf) {
                index = i;
                return true;
            }
            p = p->children[word[i] - 'a'];
        }
        if (p->leaf) {
            index = word.size() - 1;
            return true;
        }
        else {
            return false;
        }
    }

    void clear(TrieNode* node) {
        if (!node) return;
        for (int i = 0; i < 26; i++) {
            if (node->children[i]) clear(node->children[i]);
        }
        delete node;
        node = nullptr;
    }
private:
    TrieNode *root;
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        stringstream split_input(sentence);
        vector<string> sentence_words;
        string tmp = "";
        while(split_input >> tmp) sentence_words.push_back(tmp);
        Trie trie_tree;
        for (size_t i = 0; i < dictionary.size(); i++) {
            trie_tree.insertWord(dictionary[i]);
        }
        string ans = "";
        for (int i = 0; i < sentence_words.size(); i++) {
            size_t index = 0;
            if (trie_tree.searchWord(sentence_words[i], index)) {
                string swap_string = sentence_words[i].substr(0, index + 1);
                sentence_words[i] = swap_string;
            }
            if (i == sentence_words.size() - 1) {
                ans += sentence_words[i];
            }
            else {
                ans += (sentence_words[i] + " ");
            }
        }
        return ans;
    }
};
// @lc code=end


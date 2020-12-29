/*
 * @lc app=leetcode id=211 lang=cpp
 *
 * [211] Design Add and Search Words Data Structure
 *
 * https://leetcode.com/problems/design-add-and-search-words-data-structure/description/
 *
 * algorithms
 * Medium (39.31%)
 * Likes:    2590
 * Dislikes: 118
 * Total Accepted:    254.6K
 * Total Submissions: 643.2K
 * Testcase Example:  '["WordDictionary","addWord","addWord","addWord","search","search","search","search"]\n' +
  '[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]'
 *
 * Design a data structure that supports adding new words and finding if a
 * string matches any previously added string.
 * 
 * Implement the WordDictionary class:
 * 
 * 
 * WordDictionary() Initializes the object.
 * void addWord(word) Adds word to the data structure, it can be matched
 * later.
 * bool search(word) Returns true if there is any string in the data structure
 * that matches word or false otherwise. word may contain dots '.' where dots
 * can be matched with any letter.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input
 * 
 * ["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
 * [[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
 * Output
 * [null,null,null,null,false,true,true,true]
 * 
 * Explanation
 * WordDictionary wordDictionary = new WordDictionary();
 * wordDictionary.addWord("bad");
 * wordDictionary.addWord("dad");
 * wordDictionary.addWord("mad");
 * wordDictionary.search("pad"); // return False
 * wordDictionary.search("bad"); // return True
 * wordDictionary.search(".ad"); // return True
 * wordDictionary.search("b.."); // return True
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= word.length <= 500
 * word in addWord consists lower-case English letters.
 * word in search consist of  '.' or lower-case English letters.
 * At most 50000 calls will be made to addWord and search.
 * 
 * 
 */
#include <bits/stdc++.h>
using namespace std;


// @lc code=start


class TrieNode {
    public:
        TrieNode() {
            leaf = false;
            fill_n(child, 26, nullptr);
        }
        TrieNode *child[26];
        bool leaf;
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode *p = root;
        for (int i = 0; i < word.size(); i++) {
            int idx = word[i] - 'a';
            if (p->child[idx] == nullptr) p->child[idx] = new TrieNode();
            p = p->child[idx];
        }
        p->leaf = true;
    }
    
    bool search(string word) {
        TrieNode *p = root;
        return searchCore(root, word, 0);
    }


private:
    bool searchCore(TrieNode *cur, string &word, int i) {
        if (i == word.size() - 1) {
            if (word[i] == '.') {
                bool ans = false;
                for (int l = 0; l < 26; l++) {
                    if (cur->child[l] != nullptr)
                        ans = ans | (cur->child[l]->leaf);
                }
                return ans;
            }
            else {
                if (cur->child[word[i] - 'a'] == nullptr) return false;
                return cur->child[word[i] - 'a']->leaf;
            }
        }
        if (word[i] == '.') {
            bool ans = false;
            for (int l = 0; l < 26; l++) {
                if (cur->child[l] != nullptr)
                    ans = ans | searchCore(cur->child[l], word, i + 1);
            }
            return ans;
        }
        else {
            if (cur->child[word[i] - 'a'] == nullptr) return false;
            else return searchCore(cur->child[word[i] - 'a'], word, i + 1);
        }
    }
private:
   
    TrieNode *root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end


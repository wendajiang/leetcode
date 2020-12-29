/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 *
 * https://leetcode.com/problems/implement-trie-prefix-tree/description/
 *
 * algorithms
 * Medium (50.99%)
 * Likes:    4029
 * Dislikes: 62
 * Total Accepted:    375.2K
 * Total Submissions: 731.6K
 * Testcase Example:  '["Trie","insert","search","search","startsWith","insert","search"]\n' +
  '[[],["apple"],["apple"],["app"],["app"],["app"],["app"]]'
 *
 * Implement a trie with insert, search, and startsWith methods.
 * 
 * Example:
 * 
 * 
 * Trie trie = new Trie();
 * 
 * trie.insert("apple");
 * trie.search("apple");   // returns true
 * trie.search("app");     // returns false
 * trie.startsWith("app"); // returns true
 * trie.insert("app");   
 * trie.search("app");     // returns true
 * 
 * 
 * Note:
 * 
 * 
 * You may assume that all inputs are consist of lowercase letters a-z.
 * All inputs are guaranteed to be non-empty strings.
 * 
 * 
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *p = root;
        for (int i = 0; i < word.size(); i++) {
            if (p->child[word[i] - 'a'] == nullptr) p->child[word[i] - 'a'] = new TrieNode();
            p = p->child[word[i] - 'a'];
        }
        p->leaf = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *p = root;
        for (int i = 0; i < word.size(); i++) {
            if (p->child[word[i] - 'a'] == nullptr) return false;
            p = p->child[word[i] - 'a'];
        }
        if (p->leaf) return true;
        else return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *p = root;
        for (int i = 0; i < prefix.size(); i++) {
            if (p->child[prefix[i] - 'a'] == nullptr) return false;
            p = p->child[prefix[i] - 'a'];
        }
        return true;
    }
private:
    class TrieNode {
    public:
        TrieNode() {
            leaf = false;
            fill_n(child, 26, nullptr);
        }
        TrieNode *child[26];
        bool leaf;
    };

    TrieNode *root;

};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end


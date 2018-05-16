/*
 * [212] Word Search II
 *
 * https://leetcode.com/problems/word-search-ii/description/
 *
 * algorithms
 * Hard (24.84%)
 * Total Accepted:    64.6K
 * Total Submissions: 259.7K
 * Testcase Example:  '[["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]]\n["oath","pea","eat","rain"]'
 *
 *
 * Given a 2D board and a list of words from the dictionary, find all words in
 * the board.
 *
 *
 * Each word must be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring. The
 * same letter cell may not be used more than once in a word.
 *
 *
 *
 * For example,
 * Given words = ["oath","pea","eat","rain"] and board =
 *
 * [
 * ⁠ ['o','a','a','n'],
 * ⁠ ['e','t','a','e'],
 * ⁠ ['i','h','k','r'],
 * ⁠ ['i','f','l','v']
 * ]
 *
 *
 * Return ["eat","oath"].
 *
 *
 *
 * Note:
 * You may assume that all inputs are consist of lowercase letters a-z.
 *
 *
 * click to show hint.
 *
 * You would need to optimize your backtracking to pass the larger test. Could
 * you stop backtracking earlier?
 *
 * If the current candidate does not exist in all words' prefix, you could stop
 * backtracking immediately. What kind of data structure could answer such
 * query efficiently? Does a hash table work? Why or why not? How about a Trie?
 * If you would like to learn how to implement a basic trie, please work on
 * this problem: Implement Trie (Prefix Tree) first.
 *
 */
class Solution {
    class Trie{
    public:
        Trie *child[26];
        bool leaf;
        int idx;
        Trie(){
            leaf = false;
            idx = 0;
            fill_n(child, 26, nullptr);
        }
    };
    Trie* buildTrie(vector<string>& words){
        Trie* root = new Trie();
        int i;
        for(i = 0; i < words.size(); i++) insertWords(root, words, i);
        return root;
    }

    void insertWords(Trie* root, vector<string>& words, int idx){
        int pos = 0, len = words[idx].size();
        while(pos < len){
            if(nullptr == root->child[words[idx][pos] - 'a']) root->child[words[idx][pos] -'a'] = new Trie();
            root = root->child[words[idx][pos] - 'a'];
            pos++;
        }
        root->leaf = true;
        root->idx = idx;
    }

    void checkWords(vector<vector<char>>& boards, int i, int j, int row, int col ,Trie* root, vector<string>& res, vector<string>& words){
        char tmp;
        if(boards[i][j] == 'X') return;
        if(nullptr == root->child[boards[i][j] - 'a']) return; //No string with such prefix
        else{
            tmp = boards[i][j];
            if(root->child[tmp - 'a']->leaf){
                res.push_back(words[root->child[tmp - 'a']->idx]);
                root->child[tmp - 'a']->leaf = false; //set false to indicate that we found it already
            }
            boards[i][j] = 'X'; // mark the current position as visited
            if(i > 0) checkWords(boards, i - 1, j, row, col, root->child[tmp - 'a'], res, words);
            if((i + 1) < row) checkWords(boards, i + 1, j, row, col, root->child[tmp - 'a'], res, words);
            if(j > 0) checkWords(boards, i, j - 1, row, col, root->child[tmp - 'a'], res, words);
            if((j + 1) < col)  checkWords(boards, i, j + 1, row, col, root->child[tmp - 'a'], res, words);
            boards[i][j] = tmp;
        }
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        int row = board.size();
        if(0 == row) return res;
        int col = board[0].size();
        if(0 == col) return res;
        int wordCount = words.size();
        if(0 == wordCount) return res;
        Trie* root = buildTrie(words);
        int i, j;
        for(i = 0; i < row; i++){
            for(j = 0; j < col; j++){
                checkWords(board, i, j, row, col, root, res, words);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};

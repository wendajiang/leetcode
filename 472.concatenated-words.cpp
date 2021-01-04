/*
 * @lc app=leetcode id=472 lang=cpp
 *
 * [472] Concatenated Words
 *
 * https://leetcode.com/problems/concatenated-words/description/
 *
 * algorithms
 * Hard (44.95%)
 * Likes:    995
 * Dislikes: 134
 * Total Accepted:    81.7K
 * Total Submissions: 182.2K
 * Testcase Example:  '["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]'
 *
 * Given a list of words (without duplicates), please write a program that
 * returns all concatenated words in the given list of words.
 * 
 * A concatenated word is defined as a string that is comprised entirely of at
 * least two shorter words in the given array.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: words =
 * ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]
 * Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]
 * Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats"; 
 * "dogcatsdog" can be concatenated by "dog", "cats" and "dog"; 
 * "ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".
 * 
 * Example 2:
 * 
 * 
 * Input: words = ["cat","dog","catdog"]
 * Output: ["catdog"]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= words.length <= 10^4
 * 0 <= words[i].length <= 1000
 * words[i] consists of only lowercase English letters.
 * 0 <= sum(words[i].length) <= 6 * 10^5
 * 
 * 
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> result;
        if(words.empty()) return result; 
        auto mycomp = [&](const string& str1, const string& str2){return str1.size() < str2.size();};
        sort(words.begin(), words.end(), mycomp);
        unordered_set<string> mp;
        for(auto& word: words) {
            string path = "";
            if(dfs(word, 0, path, 0, mp)) result.push_back(word); // We don't need to insert this word, because it can be concatenated from other words.
            else mp.insert(word); 
        }
        return result;
    }
    
private:
    bool dfs(string& word, int pos, string& path, int cnt, unordered_set<string>& mp) {
        if(pos == word.size()) {
            if(mp.find(path) != mp.end() && cnt > 0) return true;
            else return false;
        }
        path.push_back(word[pos]);
        if(mp.find(path) != mp.end()) {
            string temp = "";
            if(dfs(word, pos+1, temp, cnt + 1, mp)) return true;
        }
        if(dfs(word, pos+1, path, cnt, mp)) return true;
        else return false;
    }
};

/*
class Solution {
public:
    struct node {
        int ch[26];
        bool flag;
        node() {
            flag = false;
            memset(ch, 0, sizeof(ch));
        }
    };
    vector<node> tree;

    void insert(string& s) {
        int add = 0;
        for (int i = 0; i < s.size(); i++) {
            int x = s[i] - 'a';
            if (!tree[add].ch[x]) {
                tree.emplace_back(node());
                tree[add].ch[x] = tree.size() - 1;
            }
            add = tree[add].ch[x];
        }
        tree[add].flag = true;
    }

    // bool isConcatenated(string& s, int add, int i, int cnt) {
    //     if (i == s.size() &&
    //         cnt >= 2) return true;
    //     else if (i == s.size()) return false;
    //     int x = s[i] - 'a';
    //     if (!tree[add].ch[x]) return false;
    //     add = tree[add].ch[x];
    //     if (tree[add].flag) return isConcatenated(s, 0, i + 1, cnt + 1) || isConcatenated(s, add, i + 1, cnt);
    //     else return isConcatenated(s, add, i + 1, cnt);
    // }

    bool isConcatenated(string& s, int begin, int cnt) {
        int add = 0;
        for (int i = begin; i < s.size(); i++) {
            int x = s[i] - 'a';
            if (tree[add].ch[x] == 0) return false;
            add = tree[add].ch[x];
            if (tree[add].flag) {
                if (i == s.size() - 1) return (cnt >= 1);
                if (isConcatenated(s, i + 1, cnt + 1)) return true;
            }
        }
        return false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        tree.emplace_back(node());
        for (int i = 0; i < words.size(); i++) {
            insert(words[i]);
        }
        vector<string> res;
        for (int i = 0; i < words.size(); i++) {
            if (isConcatenated(words[i], 0, 0)) {
                res.push_back(words[i]);
            }
        }
        return res;
    }
};
*/

// @lc code=end


/*
 * [126] Word Ladder II
 *
 * https://leetcode.com/problems/word-ladder-ii/description/
 *
 * algorithms
 * Hard (14.93%)
 * Total Accepted:    82.8K
 * Total Submissions: 554.7K
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * Given two words (beginWord and endWord), and a dictionary's word list, find
 * all shortest transformation sequence(s) from beginWord to endWord, such
 * that:
 *
 *
 * Only one letter can be changed at a time
 * Each transformed word must exist in the word list. Note that beginWord is
 * not a transformed word.
 *
 *
 * Note:
 *
 *
 * Return an empty list if there is no such transformation sequence.
 * All words have the same length.
 * All words contain only lowercase alphabetic characters.
 * You may assume no duplicates in the word list.
 * You may assume beginWord and endWord are non-empty and are not the same.
 *
 *
 * Example 1:
 *
 *
 * Input:
 * beginWord = "hit",
 * endWord = "cog",
 * wordList = ["hot","dot","dog","lot","log","cog"]
 *
 * Output:
 * [
 * ⁠ ["hit","hot","dot","dog","cog"],
 * ["hit","hot","lot","log","cog"]
 * ]
 *
 *
 * Example 2:
 *
 *
 * Input:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log"]
 *
 * Output: []
 *
 * Explanation: The endWord "cog" is not in wordList, therefore no possible
 * transformation.
 *
 *
 *
 *
 *
 */
class Solution {
public:

    // //easy bfs solution https://leetcode.com/problems/word-ladder-ii/discuss/126928/Two-concise-C++-BFS-solutions:-Standard-and-Two-end
    // vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList){
    //     vector<vector<string>> ans;
    //     unordered_set<string> dict(wordList.begin(), wordList.end());
    //     if(dict.find(endWord) == dict.end()) return ans;
    //     vector<string> visited;
    //     queue<vector<string>> q;
    //     q.push({beginWord});
    //     while(!q.empty()){
    //         int end = q.size();
    //         for(int i = 0; i < end; i++){
    //             vector<string> cur = q.front(); q.pop();
    //             string s = cur.back();
    //             for(int i = 0; i < s.size(); i++){
    //                 const char origin = s[i];
    //                 for(int j = 0; j < 26; j++){
    //                     s[i] = 'a' + j;
    //                     if(dict.find(s) == dict.end()) continue;
    //                     else{
    //                         vector<string> path = cur;
    //                         path.push_back(s);
    //                         visited.push_back(s);
    //                         if(s == endWord) ans.push_back(path);
    //                         else q.push(path);
    //                     }
    //                 }
    //                 s[i] = origin;
    //             }
    //         }
    //         for(auto &e : visited) dict.erase(e);
    //         visited.clear();
    //     }
    //     return ans;
    // }


    unordered_map<string, unordered_set<string>> parent;
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        unordered_set<string> wordlist(wordList.begin(), wordList.end());
        if(wordlist.find(endWord) == wordlist.end()) return res;

        unordered_set<string> head, tail, *phead, *ptail;
        bool got = false, isbegin = true;
        head.insert(beginWord); tail.insert(endWord);

        while(head.size() > 0 && tail.size() > 0 && !got){
            if(head.size()<=tail.size()){
                phead = &head;
                ptail = &tail;
                isbegin = true;
            }else{
                phead = &tail;
                ptail = &head;
                isbegin = false;
            }
            unordered_set<string>next;

            for(auto i= ptail->begin();i!=ptail->end();i++)
                wordlist.erase(*i);
            for(auto j= phead->begin();j!=phead->end();j++)
                wordlist.erase(*j);

            for(auto now = phead->begin();now != phead->end();now++){
                string top = *now;
                for(int i = 0; i < top.size(); i++){
                    const char origin = top[i];
                    for(int j = 0; j < 26; j++){
                        top[i] = 'a' + j;
                        if(top[i] != origin && ptail->find(top) != ptail->end()) {
                            got = true;
                            isbegin ? parent[top].insert(*(now)) : parent[*(now)].insert(top);
                        }
                        else if(top[i] != origin && wordlist.find(top) != wordlist.end()){
                            isbegin ? parent[top].insert(*(now)) : parent[*(now)].insert(top);
                            next.insert(top);
                        }
                    }
                    top[i] = origin;
                }
            }
            *phead = next;
        }
        if(got){
            vector<string> cur = {endWord};
            getPath(res, cur, beginWord, endWord);
        }
        return res;
    }

    void getPath(vector<vector<string>>& res, vector<string>& cur, const string& beginWord, string curWord){
        if(curWord == beginWord){
            reverse(cur.begin(), cur.end());
            res.push_back(cur);
            reverse(cur.begin(), cur.end());
            return;
        }
        for(auto itr : parent[curWord]){
            cur.push_back(itr);
            getPath(res, cur, beginWord, itr);
            cur.pop_back();
        }
    }
};

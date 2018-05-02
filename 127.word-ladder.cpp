/*
 * [127] Word Ladder
 *
 * https://leetcode.com/problems/word-ladder/description/
 *
 * algorithms
 * Medium (20.07%)
 * Total Accepted:    163.4K
 * Total Submissions: 812K
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * Given two words (beginWord and endWord), and a dictionary's word list, find
 * the length of shortest transformation sequence from beginWord to endWord,
 * such that:
 *
 *
 * Only one letter can be changed at a time.
 * Each transformed word must exist in the word list. Note that beginWord is
 * not a transformed word.
 *
 *
 * Note:
 *
 *
 * Return 0 if there is no such transformation sequence.
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
 * Output: 5
 *
 * Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" ->
 * "dog" -> "cog",
 * return its length 5.
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
 * Output: 0
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
    // //自己做的可以A， 慢的不行，5.91%
    // bool judge(string& a, string& b){
    //     bool first = true;
    //     int i = 0;
    //     while(i < a.size()){
    //         if(a[i] == b[i]){
    //             i++;
    //         }else if(a[i] != b[i] && first){
    //             first = false;
    //             i++;
    //         }else{
    //             break;
    //         }
    //     }
    //     return (i == a.size() && !first); // 只有一个字母不同
    // }
    //
    // vector<vector<string>> buildG(vector<string>& gg){
    //     int len = gg.size();
    //     vector<vector<string>> GG(len);
    //     for(int i = 0; i < gg.size(); i++){
    //         for(int j = 0; j < gg.size(); j++){
    //             if(j != i && judge(gg[i], gg[j])){
    //                 GG[i].push_back(gg[j]);
    //             }
    //         }
    //     }
    //     return GG;
    // }
    //
    // int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    //     if(beginWord.size() != endWord.size()) return 0;
    //     int vis = false;
    //     for(int i = 0; i < wordList.size(); i++){
    //         if(wordList[i] == endWord)
    //             vis = true;
    //     }
    //     if(!vis){
    //         return 0;
    //     }else{
    //         int len = 0;
    //         vector<string> gg;
    //         unordered_map<string, int> mp;
    //         gg.push_back(beginWord);
    //         mp[beginWord] = 0;
    //         for(int i = 0; i < wordList.size(); i++){
    //             if(wordList[i].size() == endWord.size()){
    //                 gg.push_back(wordList[i]);
    //                 mp[wordList[i]] = i + 1;
    //             }
    //         }
    //         vector<vector<string>> GG = buildG(gg);
    //         set<string> vis;
    //         vector<string> Q;
    //         Q.push_back(beginWord);
    //         int l = 0, r = 1;
    //         int step = 0;
    //         while(l < r){
    //             int end = r;
    //             step++;
    //             for(int i = l; i < end; i++){
    //                 string cur = Q[i];
    //                 if(cur == endWord) return step;
    //                 int idx = mp[cur];
    //                 vis.insert(cur);
    //                 for(int j = 0; j < GG[idx].size(); j++){
    //                     if(vis.count(GG[idx][j]) == 0){
    //                         Q.push_back(GG[idx][j]);
    //                     }
    //                 }
    //             }
    //             l = end;
    //             r = Q.size();
    //         }
    //
    //         return 0;
    //     }
    // }

    //两端搜索 https://leetcode.com/problems/word-ladder/discuss/40707/Easy-76ms-C++-Solution-using-BFS
    int ladderLength(string beginWord, string endWord, vector<string>& wordList){
        unordered_set<string> wordlist(wordList.begin(), wordList.end());
        if(wordlist.find(endWord) == wordlist.end()) return 0;
        unordered_set<string> head, tail, *phead, *ptail;
        head.insert(beginWord);
        tail.insert(endWord);
        int dist = 2;
        while(!head.empty() && !tail.empty()){
            if(head.size() < tail.size()){
                phead = &head;
                ptail = &tail;
            }else{
                phead = &tail;
                ptail = &head;
            }
            unordered_set<string> tmp;
            for(auto itr  = phead->begin(); itr != phead->end(); itr++){
                string word = *itr;
                wordlist.erase(word);
                for(int i = 0; i < word.size(); i++){
                    const char origin = word[i];
                    for(int j = 0; j < 26; j++){
                        word[i] = 'a' + j;
                        if(ptail->find(word) != ptail->end()){
                            return dist;
                        }
                        if(wordlist.find(word) != wordlist.end()){
                            tmp.insert(word);
                            wordlist.erase(word);
                        }
                    }
                    word[i] = origin;
                }
            }
            dist++;
            swap(*phead, tmp); //只保存一层bfs的内容
        }
        return 0;
    }
};

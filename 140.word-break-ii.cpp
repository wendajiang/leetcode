/*
 * [140] Word Break II
 *
 * https://leetcode.com/problems/word-break-ii/description/
 *
 * algorithms
 * Hard (24.40%)
 * Total Accepted:    111.6K
 * Total Submissions: 455.6K
 * Testcase Example:  '"catsanddog"\n["cat","cats","and","sand","dog"]'
 *
 *
 * Given a non-empty string s and a dictionary wordDict containing a list of
 * non-empty words, add spaces in s to construct a sentence where each word is
 * a valid dictionary word. You may assume the dictionary does not contain
 * duplicate words.
 *
 *
 *
 * Return all such possible sentences.
 *
 *
 *
 * For example, given
 * s = "catsanddog",
 * dict = ["cat", "cats", "and", "sand", "dog"].
 *
 *
 *
 * A solution is ["cats and dog", "cat sand dog"].
 *
 *
 *
 * UPDATE (2017/1/4):
 * The wordDict parameter had been changed to a list of strings (instead of a
 * set of strings). Please reload the code definition to get the latest
 * changes.
 *
 */
class Solution {
public:
    // //自己做的
    // vector<string> res;
    // vector<vector<int>> paths;
    // void dfs(vector<vector<int>>& G, int cur, int dist, vector<int> tmp){
    //     vector<int> &curL = G[cur];
    //     for(int i = 0; i < curL.size(); i++){
    //         tmp.push_back(curL[i]);
    //         if(curL[i] == dist){
    //             paths.push_back(tmp);
    //             return;
    //         }
    //         dfs(G, curL[i], dist, tmp);
    //         tmp.pop_back();
    //     }
    // }
    // vector<string> wordBreak(string s, vector<string>& wordDict) {
    //     int len = s.size();
    //     if(len == 0) {
    //         return res;
    //     }
    //     set<string> dict;
    //     for(int i = 0; i < wordDict.size(); i++)
    //         dict.insert(wordDict[i]);
    //     vector<bool> dp(len + 1, false);
    //     vector<vector<int>> path(len + 1);
    //
    //     dp[0] = true;
    //
    //     for(int pos = 0; pos < len; pos++){
    //         for(int i = pos; dp[pos] && i < len; i++){
    //             if(dict.find(s.substr(pos, i - pos + 1)) != dict.end()){
    //                 dp[i + 1] = true;
    //                 path[pos].push_back(i + 1);
    //             }
    //         }
    //     }
    //     if(dp[len] == false) return res;
    //     vector<int> tmp;
    //     dfs(path, 0, len, tmp);
    //     for(int i = 0; i < paths.size(); i++){
    //         string ans = "";
    //         int pre = 0;
    //         for(int j = 0; j < paths[i].size() - 1; j++){
    //             ans += s.substr(pre, paths[i][j] - pre) + " ";
    //             pre = paths[i][j];
    //         }
    //         ans += s.substr(pre, paths[i][paths[i].size() - 1] - pre);
    //         res.push_back(ans);
    //     }
    //     return res;
    // }

    //直接dfs做，通过map记忆搜索
    vector<string> wordBreak(string s, vector<string>& wordDict){
        unordered_set<string> dict;
        for(int i = 0; i < wordDict.size(); i++)
            dict.insert(wordDict[i]);
        return wordBreak(s, dict);
    }

    vector<string> wordBreak(string s, unordered_set<string> &dict){
        vector<string> res;
        if(dict.find(s) != dict.end())
            res.push_back(s);
        for(int i = 1; i < s.size(); i++){
            string w = s.substr(i);
            if(dict.find(w) == dict.end())
                continue;
            string str = s.substr(0,i);
            vector<string> left = wordBreak(str,dict);
            for(vector<string>::iterator it = left.begin(); it != left.end(); it++){
                *it += " " + w;
            }
            res.insert(res.begin(), left.begin(), left.end());
        }
        return res;
    }

};

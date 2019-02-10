/*
 * [139] Word Break
 *
 * https://leetcode.com/problems/word-break/description/
 *
 * algorithms
 * Medium (31.38%)
 * Total Accepted:    205K
 * Total Submissions: 651.7K
 * Testcase Example:  '"leetcode"\n["leet","code"]'
 *
 *
 * Given a non-empty string s and a dictionary wordDict containing a list of
 * non-empty words, determine if s can be segmented into a space-separated
 * sequence of one or more dictionary words. You may assume the dictionary does
 * not contain duplicate words.
 *
 *
 * For example, given
 * s = "leetcode",
 * dict = ["leet", "code"].
 *
 *
 *
 * Return true because "leetcode" can be segmented as "leet code".
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
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.length();
        set<string> dict;
        for(int i = 0; i < wordDict.size(); i++)
            dict.insert(wordDict[i]);
        vector<bool> dp(len + 1, false);
        dp[0] = true;
        for(int pos = 0; pos < len; pos++){
            for(int i = pos; dp[pos] && i < len; i++){
                if(dict.find(s.substr(pos, i - pos + 1)) != dict.end()){
                    dp[i + 1] = true;
                }
            }
        }
        return dp[len];
    }
};

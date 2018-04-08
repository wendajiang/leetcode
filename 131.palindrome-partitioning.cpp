/*
 * [131] Palindrome Partitioning
 *
 * https://leetcode.com/problems/palindrome-partitioning/description/
 *
 * algorithms
 * Medium (35.43%)
 * Total Accepted:    118.7K
 * Total Submissions: 333K
 * Testcase Example:  '"aab"'
 *
 *
 * Given a string s, partition s such that every substring of the partition is
 * a palindrome.
 *
 *
 * Return all possible palindrome partitioning of s.
 *
 *
 * For example, given s = "aab",
 *
 * Return
 *
 * [
 * ⁠ ["aa","b"],
 * ⁠ ["a","a","b"]
 * ]
 *
 *
 */
class Solution {
public:
    void dfs(string s, int index, vector<vector<string>>& res, vector<string> tmp, vector<vector<bool>>& dp ){
        if(index == s.size()){
            res.push_back(tmp);
            return;
        }
        for(int i = index; i < s.size(); i++){
            if(dp[index][i]){
                tmp.push_back(s.substr(index, i - index + 1));
                dfs(s, i + 1, res, tmp, dp);
                tmp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int len = s.size();
        vector<vector<bool>> dp(len, vector<bool>(len, 0));
        for(int j = 0; j < len; j++){
            for(int i = 0; i < len; i++){
                if(j >= i){
                    if(i == j) dp[i][j] = true;
                    else if(i + 1 == j) dp[i][j] = (s[i] == s[j]);
                    else dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
                }

            }
        }
        vector<vector<string>> res;
        vector<string> tmp;
        dfs(s, 0, res, tmp, dp);
        return res;

    }
};

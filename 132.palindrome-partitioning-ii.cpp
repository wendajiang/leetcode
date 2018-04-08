/*
 * [132] Palindrome Partitioning II
 *
 * https://leetcode.com/problems/palindrome-partitioning-ii/description/
 *
 * algorithms
 * Hard (24.78%)
 * Total Accepted:    80.6K
 * Total Submissions: 324.5K
 * Testcase Example:  '"aab"'
 *
 *
 * Given a string s, partition s such that every substring of the partition is
 * a palindrome.
 *
 *
 * Return the minimum cuts needed for a palindrome partitioning of s.
 *
 *
 * For example, given s = "aab",
 * Return 1 since the palindrome partitioning ["aa","b"] could be produced
 * using 1 cut.
 *
 */
class Solution {
public:

    // // TLE，按照131的思路来做的
    // void dfs(int index, string& s, int& res, int cur, vector<vector<bool>>& dp){
    //     if(index == s.size()){
    //         res = min(res, cur);
    //     }
    //     for(int i = index; i < s.size(); i++){
    //         if(dp[index][i]){
    //             cur ++;
    //             dfs(i + 1, s, res, cur, dp);
    //             cur --;
    //         }
    //     }
    // }
    // int minCut(string s) {
    //     int len = s.size();
    //     vector<vector<bool>> dp(len, vector<bool>(len, 0));
    //
    //     for(int j = 0; j < len; j++){
    //         for(int i = 0; i < len; i++){
    //             if(j >= i){
    //                 if(i == j) dp[i][j] = true;
    //                 else if(i + 1 == j) dp[i][j] = (s[i] == s[j]);
    //                 else dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
    //             }
    //         }
    //     }
    //     //dp有了，找到截止最小
    //     int res = INT_MAX;
    //     dfs(0, s, res, 0, dp);
    //     return res - 1;
    // }

    int minCut(string s){
        int len = s.size();
        if(len < 2) return 0;
        vector<vector<bool>> dp(len, vector<bool>(len, 0));
        vector<int> minL(len + 1, -1);
        for(int i = 0;i < len; i++) minL[i] = len - i - 1;

        for(int i = len - 1; i >= 0; i--){
            for(int j = i; j < len; j++ ) {
                if(s[i] == s[j] && (j - i < 2 || dp[i + 1][j - 1])){
                    dp[i][j] = true;
                    minL[i] = min(minL[i], minL[j + 1] + 1);
                }
            }
        }

        return minL[0];
    }
};

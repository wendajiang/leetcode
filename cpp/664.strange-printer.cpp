/*
 * [664] Strange Printer
 *
 * https://leetcode.com/problems/strange-printer/description/
 *
 * algorithms
 * Hard (34.11%)
 * Total Accepted:    5.1K
 * Total Submissions: 14.9K
 * Testcase Example:  '"aaabbb"'
 *
 *
 * There is a strange printer with the following two special requirements:
 *
 *
 * The printer can only print a sequence of the same character each time.
 * At each turn, the printer can print new characters starting from and ending
 * at any places, and will cover the original existing characters.
 *
 *
 *
 *
 *
 * Given a string consists of lower English letters only, your job is to count
 * the minimum number of turns the printer needed in order to print it.
 *
 *
 * Example 1:
 *
 * Input: "aaabbb"
 * Output: 2
 * Explanation: Print "aaa" first and then print "bbb".
 *
 *
 *
 * Example 2:
 *
 * Input: "aba"
 * Output: 2
 * Explanation: Print "aaa" first and then print "b" from the second place of
 * the string, which will cover the existing character 'a'.
 *
 *
 *
 * Hint: Length of the given string will not exceed 100.
 */
class Solution {
public:
    // /*
    // dp[i][j] minimum steps to print s[i...j]
    // dp[i][j] = j - i + 1 worse case
    //
    // dp[i][j] = dp[i][k] + dp[k + 1][j]
    // aba -- 2
    // dp[i][k] = a = 1
    // dp[k + 1][j] = ba = 2 多出了
    //
    // ->
    // if(s[k] == s[j]) dp[i][j] = dp[i][k] + dp[k + 1][j] - 1
    //
    // */
    // int strangePrinter(string s) {
    //     int len = s.size();
    //     if(len == 0) return 0;
    //     vector<vector<int>> dp(len, vector<int>(len, 0));
    //     for(int i = 0; i < len; i++) dp[i][i] = 1;
    //
    //     for(int kk = 1; kk < len; kk++){
    //         for(int l = 0; l + kk < len; l++){
    //             int r = l + kk;
    //             dp[l][r] = kk + 1;
    //             for(int k = l + 1; k <= r; k++){
    //                 int tmp = dp[l][k - 1] + dp[k][r];
    //                 if(s[k - 1] == s[r]) tmp--;
    //                 dp[l][r] = min(dp[l][r], tmp);
    //             }
    //         }
    //     }
    //     return dp[0][len - 1];
    // }


    //记忆化搜索 https://leetcode.com/problems/strange-printer/discuss/106811/C++-29ms-DP-solution
    int strangePrinter(string s){
        memset(f, 0, sizeof(f));
        int len = (int)s.size();
        return dfs(s, 0, len - 1);
    }

private:
    int f[100][100];
    int dfs(const string &s, int l, int r){
        if(l > r) return 0;
        if(f[l][r]) return f[l][r];
        f[l][r] = dfs(s, l, r - 1) + 1;
        for(int i = l; i < r; i++){
            if(s[i] == s[r]){
                f[l][r] = min(f[l][r], dfs(s, l, i) + dfs(s, i + 1, r - 1));
            }
        }
        return f[l][r];
    }
};

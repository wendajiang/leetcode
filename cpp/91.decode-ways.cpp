/*
 * [91] Decode Ways
 *
 * https://leetcode.com/problems/decode-ways
 *
 * Medium (19.47%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '""'
 *
 *
 * A message containing letters from A-Z is being encoded to numbers using the
 * following mapping:
 *
 *
 *
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 *
 *
 *
 * Given an encoded message containing digits, determine the total number of
 * ways to decode it.
 *
 *
 *
 * For example,
 * Given encoded message "12",
 * it could be decoded as "AB" (1 2) or "L" (12).
 *
 *
 *
 * The number of ways decoding "12" is 2.
 *
 */
class Solution {
public:
    int numDecodings(string s) {
        if(s.size() == 0 || s[0] == '0') return 0;
        vector<int> dp(s.size() + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= s.size(); i++){
            if(s[i - 1] == '0'){
                if(s[i - 2] == '1' || s[i - 2] == '2')
                    dp[i] = dp[i - 2];
                else
                    return 0;
            }else if(s[i - 1] >= '1' && s[i - 1] <= '9'){
                dp[i] = dp[i - 1];
                if(s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6')){
                    dp[i] += dp[i - 2];
                }
            }
        }
        return dp[s.size()];

        // //来自一本书上的解法，但是并不直观，优化过后的，空间复杂度优化为O(1)
        // if(s.size() == 0 || s[0] == '0') return 0;
        // if(s.size() == 1) return check(s[0]);
        // int fn = 0, fn1 = 0, fn2 = 1;
        // fn1 = (check(s[0]) * check(s[1])) + check(s[0], s[1]);
        // for(int i = 2; i < s.size(); i++){
        //     if(check(s[i])) fn += fn1;
        //     if(check(s[i - 1], s[i])) fn += fn2;
        //     if(fn == 0) return 0;
        //     fn2 = fn1;
        //     fn1 = fn;
        //     fn = 0;
        // }
        // return fn1;
    }

    int check(char c){
        return c == '0' ? 0 : 1;
    }
    int check(char c1, char c2){
        return (c1 == '1' || (c1 == '2' && c2 <= '6')) ? 1 : 0;
    }
};

/*
 * [730] Count Different Palindromic Subsequences
 *
 * https://leetcode.com/problems/count-different-palindromic-subsequences/description/
 *
 * algorithms
 * Hard (35.19%)
 * Total Accepted:    2.8K
 * Total Submissions: 7.8K
 * Testcase Example:  '"bccb"'
 *
 *
 * Given a string S, find the number of different non-empty palindromic
 * subsequences in S, and return that number modulo 10^9 + 7.
 *
 * A subsequence of a string S is obtained by deleting 0 or more characters
 * from S.
 *
 * A sequence is palindromic if it is equal to the sequence reversed.
 *
 * Two sequences A_1, A_2, ... and B_1, B_2, ... are different if there is some
 * i for which A_i != B_i.
 *
 *
 * Example 1:
 *
 * Input:
 * S = 'bccb'
 * Output: 6
 * Explanation:
 * The 6 different non-empty palindromic subsequences are 'b', 'c', 'bb', 'cc',
 * 'bcb', 'bccb'.
 * Note that 'bcb' is counted only once, even though it occurs twice.
 *
 *
 *
 * Example 2:
 *
 * Input:
 * S = 'abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba'
 * Output: 104860361
 * Explanation:
 * There are 3104860382 different non-empty palindromic subsequences, which is
 * 104860361 modulo 10^9 + 7.
 *
 *
 *
 * Note:
 * The length of S will be in the range [1, 1000].
 * Each character S[i] will be in the set {'a', 'b', 'c', 'd'}.
 *
 */
class Solution {
public:

    /*
    源自： https://www.cnblogs.com/grandyang/p/7942040.html
    分析：
    1. 当S[i]不等于S[j]的时候，
    dp[i][j] = dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1]
    2. S[i] == S[j]
    因为我们不知道中间还有几个和S[i]相等的值所以要分情况讨论
    举个简单的例子，比如"aba"和"aaa"，
    当i = 0, j = 2的时候，两个字符串均有S[i] == S[j]，
    此时二者都新增两个子序列"a"和"aa"，
    但是"aba"中间的"b"就可以加到结果res中，
    而"aaa"中的"a"就不能加了，因为和外层的单独"a"重复了。
    我们的目标就要找到中间重复的"a"。
    所以我们让left = i + 1, right = j - 1，
    然后对left进行while循环，如果left <= right, 且S[left] != S[i]的时候，
    left向右移动一个；同理，对right进行while循环，
    如果left <= right, 且S[right] != S[i]的时候，
    right向左移动一个。这样最终left和right值就有三种情况：
    2.1 当left > righ时，
    说明中间没有和S[i]相同的字母了，就是"aba"这种情况，
    那么就有dp[i][j] = dp[i + 1][j - 1] * 2 + 2，
    其中dp[i + 1][j - 1]是中间部分的回文子序列个数，
    为啥要乘2呢，因为中间的所有子序列可以单独存在，
    也可以再外面包裹上字母a，所以是成对出现的，要乘2。
    加2的原因是外层的"a"和"aa"也要统计上。

    2.2 当left = right时，说明中间只有一个和S[i]相同的字母，
    就是"aaa"这种情况，那么有dp[i][j] = dp[i + 1][j - 1] * 2 + 1，
    其中乘2的部分跟上面的原因相同，
    加1的原因是单个字母"a"的情况已经在中间部分算过了，外层就只能再加上个"aa"了。

    2.3 当left < right时，说明中间至少有两个和S[i]相同的字母，
    就是"aabaa"这种情况，
    那么有dp[i][j] = dp[i + 1][j - 1] * 2 - dp[left + 1][right - 1]，
    其中乘2的部分跟上面的原因相同，
    要减去left和right中间部分的子序列个数的原因是其被计算了两遍，要将多余的减掉。


    */
    const int MOD = 1e9 + 7;
    int countPalindromicSubsequences(string S) {
        int len = S.size();
        int dp[len][len];
        memset(dp, 0, sizeof(dp));
        for(int i = len - 1; i >= 0; i--){
            dp[i][i] = 1;
            for(int j = i + 1; j < len; j++){
                if (S[i] == S[j]) {
                    int left = i + 1, right = j - 1;
                    while (left <= right && S[left] != S[i]) ++left;
                    while (left <= right && S[right] != S[i]) --right;
                    if (left > right) {
                        dp[i][j] = dp[i + 1][j - 1] * 2 + 2;
                    } else if (left == right) {
                        dp[i][j] = dp[i + 1][j - 1] * 2 + 1;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1] * 2 - dp[left + 1][right - 1];
                    }
                } else {
                    dp[i][j] = dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1];
                }
                dp[i][j] = (dp[i][j] < 0) ? dp[i][j] + MOD : dp[i][j] % MOD;
            }
        }
        return dp[0][len - 1];
    }
};

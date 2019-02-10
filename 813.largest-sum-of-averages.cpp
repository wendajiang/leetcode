/*
 * [831] Largest Sum of Averages
 *
 * https://leetcode.com/problems/largest-sum-of-averages/description/
 *
 * algorithms
 * Medium (39.51%)
 * Total Accepted:    2.9K
 * Total Submissions: 7.3K
 * Testcase Example:  '[9,1,2,3,9]\n3'
 *
 * We partition a row of numbers A into at most K adjacent (non-empty) groups,
 * then our score is the sum of the average of each group. What is the largest
 * score we can achieve?
 *
 * Note that our partition must use every number in A, and that scores are not
 * necessarily integers.
 *
 *
 * Example:
 * Input:
 * A = [9,1,2,3,9]
 * K = 3
 * Output: 20
 * Explanation:
 * The best choice is to partition A into [9], [1, 2, 3], [9]. The answer is 9
 * + (1 + 2 + 3) / 3 + 9 = 20.
 * We could have also partitioned A into [9, 1], [2], [3, 9], for example.
 * That partition would lead to a score of 5 + 2 + 6 = 13, which is worse.
 *
 *
 *
 *
 * Note:
 *
 *
 * 1 <= A.length <= 100.
 * 1 <= A[i] <= 10000.
 * 1 <= K <= A.length.
 * Answers within 10^-6 of the correct answer will be accepted as correct.
 *
 *
 */
class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        int len = A.size();
        vector<int> sum(len, 0);
        sum[0] = A[0];
        for(int i = 1; i < len; i++) sum[i] = sum[i - 1] + A[i];
        vector<vector<double>> dp(len, vector<double>(K, 0.0));
        for(int i = 0; i < len; i++){
            for(int k = 0; k < K; k++){
                dp[i][k] = (k == 0) ? (double)sum[i] / (i + 1) : dp[i][k - 1];
                if(k > 0){
                    for(int j = i - 1; j >= 0; j--)
                        dp[i][k] = max(dp[i][k], dp[j][k - 1] + (double)(sum[i] - sum[j]) / (i - j));
                }
            }
        }
        return dp[len - 1][K - 1];
    }
};

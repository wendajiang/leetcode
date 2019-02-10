/*
 * [279] Perfect Squares
 *
 * https://leetcode.com/problems/perfect-squares/description/
 *
 * algorithms
 * Medium (37.79%)
 * Total Accepted:    110K
 * Total Submissions: 290.9K
 * Testcase Example:  '1'
 *
 *
 * Given a positive integer n, find the least number of perfect square numbers
 * (for example, 1, 4, 9, 16, ...) which sum to n.
 *
 *
 *
 * For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13,
 * return 2 because 13 = 4 + 9.
 *
 *
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and
 * creating all test cases.
 */
class Solution {
public:
    int numSquares(int n) {
        if(n == 0) return 0;
        vector<int> nums;
        for(int i = 1; i * i <= n; i++){
            nums.push_back(i * i);
        }
        vector<int> dp(n + 1, 0x7ffffffe);
        dp[0] = 0;
        for(int j = 0; j < nums.size(); j++){
            for(int i = nums[j]; i <= n; i++)
                dp[i] = min(dp[i], dp[i - nums[j]] + 1);
        }
        return dp[n];
    }
};

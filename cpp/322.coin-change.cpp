/*
 * [322] Coin Change
 *
 * https://leetcode.com/problems/coin-change/description/
 *
 * algorithms
 * Medium (26.60%)
 * Total Accepted:    95.1K
 * Total Submissions: 357.4K
 * Testcase Example:  '[1]\n0'
 *
 *
 * You are given coins of different denominations and a total amount of money
 * amount. Write a function to compute the fewest number of coins that you need
 * to make up that amount. If that amount of money cannot be made up by any
 * combination of the coins, return -1.
 *
 *
 *
 * Example 1:
 * coins = [1, 2, 5], amount = 11
 * return 3 (11 = 5 + 5 + 1)
 *
 *
 *
 * Example 2:
 * coins = [2], amount = 3
 * return -1.
 *
 *
 *
 * Note:
 * You may assume that you have an infinite number of each kind of coin.
 *
 *
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and
 * creating all test cases.
 */
class Solution {
public:
    //变换循环顺序，需要改变最大值，0x7fffffff + 1为大负数所以要改为0x7ffffffe + 1为最大的int型的数
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, 0x7ffffffe);
        dp[0] = 0;
        for(int j = 0; j < coins.size(); j++){
            for(int i = coins[j]; i <= amount; i++){
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
        return dp[amount] == 0x7ffffffe ? -1 : dp[amount];
    }
};

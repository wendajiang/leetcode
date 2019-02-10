/*
 * [312] Burst Balloons
 *
 * https://leetcode.com/problems/burst-balloons/description/
 *
 * algorithms
 * Hard (43.77%)
 * Total Accepted:    38.7K
 * Total Submissions: 88.4K
 * Testcase Example:  '[3,1,5,8]'
 *
 *
 * ⁠   Given n balloons, indexed from 0 to n-1. Each balloon is painted with a
 * ⁠   number on it represented by array nums.
 *
 * ⁠   You are asked to burst all the balloons. If the you burst
 * ⁠   balloon i you will get nums[left] * nums[i] * nums[right] coins. Here
 * left
 * ⁠   and right are adjacent indices of i. After the burst, the left and right
 * ⁠   then becomes adjacent.
 *
 *
 * ⁠   Find the maximum coins you can collect by bursting the balloons
 * wisely.
 *
 *
 * ⁠   Note:
 * ⁠   (1) You may imagine nums[-1] = nums[n] = 1. They are not real therefore
 * you can not burst them.
 * ⁠   (2) 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100
 *
 *
 *
 *
 * ⁠   Example:
 *
 *
 * ⁠   Given [3, 1, 5, 8]
 *
 *
 * ⁠   Return 167
 *
 *
 * ⁠   nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
 * ⁠  coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
 *
 *
 * Credits:Special thanks to @dietpepsi for adding this problem and creating
 * all test cases.
 */
class Solution {
public:

    /*
    区间DP
    
    思路：
    考虑最后一个戳破的气球，这个气球的位置可以把整个区间分为两部分
    dp[l][r]: nums[l]...nums[r]能戳破气球的最大值

    递推关系：
    l < m < r nums[m]假设是l...r中最后戳破的气球
    for(m = l + 1 ... r - 1)
        max(dp[l][m] + dp[m][r] + nums[l] * nums[m] * nums[r])

    初始值：
        扩展nums，前后各加一个扩展一个1
        dp[l][r] : l + 1 == r || l == r  dp[l][r] = 0
                   l + 2 == r dp[l][r] = nums[l] * nums[l + 1] * nums[l + 2]
    */
    int maxCoins(vector<int>& nums) {
        int len = nums.size() + 2;
        vector<int> newnums(len);
        newnums[0] = newnums[len - 1] = 1;
        for(int i = 1; i < len - 1; i ++){
            newnums[i] = nums[i - 1];
        }
        vector<vector<int>> dp(len, vector<int>(len, 0));
        for(int k = 2; k < len; k++){
            for(int l = 0; l + k < len; l++){
                int r = l + k;
                for(int m = l + 1; m < r; m++){
                    dp[l][r] = max(dp[l][r], newnums[l] * newnums[m] * newnums[r] + dp[l][m] + dp[m][r]);
                }
            }
        }
        return dp[0][len - 1];
    }
};

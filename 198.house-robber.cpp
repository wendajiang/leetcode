/*
 * [198] House Robber
 *
 * https://leetcode.com/problems/house-robber
 *
 * Easy (38.69%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[]'
 *
 * You are a professional robber planning to rob houses along a street. Each
 * house has a certain amount of money stashed, the only constraint stopping
 * you from robbing each of them is that adjacent houses have security system
 * connected and it will automatically contact the police if two adjacent
 * houses were broken into on the same night.
 *
 * Given a list of non-negative integers representing the amount of money of
 * each house, determine the maximum amount of money you can rob tonight
 * without alerting the police.
 *
 * Credits:Special thanks to @ifanchu for adding this problem and creating all
 * test cases. Also thanks to @ts for adding additional test cases.
 */
class Solution {
public:
    /*
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    dp[i] = max(dp[i - 2] + nums[i], dp[i - 1])

    */
    int rob(vector<int>& nums) {
        int rob = 0;
        int notrob = 0;
        for(int i = 0; i < nums.size(); i++){
            int currob = notrob + nums[i];
            notrob = std::max(notrob, rob);
            rob = currob;
        }
        return std::max(rob, notrob);
    }
};

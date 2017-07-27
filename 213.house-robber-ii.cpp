/*
 * [213] House Robber II
 *
 * https://leetcode.com/problems/house-robber-ii
 *
 * Medium (33.86%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[]'
 *
 * Note: This is an extension of House Robber.
 *
 * After robbing those houses on that street, the thief has found himself a new
 * place for his thievery so that he will not get too much attention. This
 * time, all houses at this place are arranged in a circle. That means the
 * first house is the neighbor of the last one. Meanwhile, the security system
 * for these houses remain the same as for those in the previous street.
 *
 * Given a list of non-negative integers representing the amount of money of
 * each house, determine the maximum amount of money you can rob tonight
 * without alerting the police.
 *
 * Credits:Special thanks to @Freezen for adding this problem and creating all
 * test cases.
 */
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return std::max(nums[0], nums[1]);
        return std::max(rob(nums, 0, nums.size() - 2), rob(nums, 1, nums.size() - 1));
    }
    int rob(vector<int>& nums, int start, int end){
        vector<int> dp(end - start + 1, 0);
        if(end - start + 1 == 1) return nums[start];
        if(end - start + 1 == 2) return std::max(nums[start], nums[end]);
        dp[0] = nums[start];
        dp[1] = std::max(nums[start], nums[start + 1]);
        for(int i = 2; i < end - start + 1; i++){
            dp[i] = std::max(dp[i - 2] + nums[start + i], dp[i - 1]);
        }
        return dp[end - start];
    }
};

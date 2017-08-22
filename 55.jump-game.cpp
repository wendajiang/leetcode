/*
 * [55] Jump Game
 *
 * https://leetcode.com/problems/jump-game
 *
 * algorithms
 * Medium (29.52%)
 * Total Accepted:    129.3K
 * Total Submissions: 438K
 * Testcase Example:  '[2,3,1,1,4]'
 *
 *
 * Given an array of non-negative integers, you are initially positioned at the
 * first index of the array.
 *
 *
 * Each element in the array represents your maximum jump length at that
 * position.
 *
 *
 * Determine if you are able to reach the last index.
 *
 *
 *
 * For example:
 * A = [2,3,1,1,4], return true.
 *
 *
 * A = [3,2,1,0,4], return false.
 *
 */
class Solution {
public:
    //greedy
    bool canJump(vector<int>& nums) {
        int reach = 0;
        for(int i = 0; i < nums.size() - 1 && i <= reach; i++){
            reach = std::max(i + nums[i], reach);
        }
        return reach >= nums.size() - 1;
    }
};

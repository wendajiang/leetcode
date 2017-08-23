/*
 * [45] Jump Game II
 *
 * https://leetcode.com/problems/jump-game-ii
 *
 * algorithms
 * Hard (26.20%)
 * Total Accepted:    96.9K
 * Total Submissions: 369.7K
 * Testcase Example:  '[0]'
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
 * Your goal is to reach the last index in the minimum number of jumps.
 *
 *
 *
 * For example:
 * Given array A = [2,3,1,1,4]
 *
 *
 * The minimum number of jumps to reach the last index is 2. (Jump 1 step from
 * index 0 to 1, then 3 steps to the last index.)
 *
 *
 *
 * Note:
 * You can assume that you can always reach the last index.
 */
class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size();
        if(len < 2) return 0;
        int maxReach = 0, curReach = 0;
        int level = 0;
        while(maxReach < nums.size() - 1){
            int n = maxReach;
            for(int i = curReach; i <= n; i ++){
                maxReach = std::max(i + nums[i], maxReach);
            }
            curReach = n + 1;
            level ++;
        }
        return level;
    }
};

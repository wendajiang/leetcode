/*
 * @lc app=leetcode id=398 lang=cpp
 *
 * [398] Random Pick Index
 *
 * https://leetcode.com/problems/random-pick-index/description/
 *
 * algorithms
 * Medium (56.90%)
 * Likes:    553
 * Dislikes: 750
 * Total Accepted:    103K
 * Total Submissions: 180.9K
 * Testcase Example:  '["Solution","pick"]\n[[[1,2,3,3,3]],[3]]'
 *
 * Given an array of integers with possible duplicates, randomly output the
 * index of a given target number. You can assume that the given target number
 * must exist in the array.
 * 
 * Note:
 * The array size can be very large. Solution that uses too much extra space
 * will not pass the judge.
 * 
 * Example:
 * 
 * 
 * int[] nums = new int[] {1,2,3,3,3};
 * Solution solution = new Solution(nums);
 * 
 * // pick(3) should return either index 2, 3, or 4 randomly. Each index should
 * have equal probability of returning.
 * solution.pick(3);
 * 
 * // pick(1) should return 0. Since in the array only nums[0] is equal to 1.
 * solution.pick(1);
 * 
 * 
 */
#include <bits/stdc++.h>
// @lc code=start
class Solution {
public:
    Solution(vector<int>& nums) {
        this->nums = std::move(nums);
    }
    
    int pick(int target) {
        int cnt = 0;
        int res = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                cnt ++;
                if (res == -1) {
                    res = i;
                }
                else {
                    if (rand() % cnt == 0) {
                        res = i;
                    }
                }                
            }
        }
        return res;
    }

private:
    vector<int> nums;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
// @lc code=end


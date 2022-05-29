/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 *
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (38.99%)
 * Likes:    10780
 * Dislikes: 295
 * Total Accepted:    1.1M
 * Total Submissions: 2.8M
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * Given an array of integers nums sorted in non-decreasing order, find the
 * starting and ending position of a given target value.
 *
 * If target is not found in the array, return [-1, -1].
 *
 * You must write an algorithm with O(log n) runtime complexity.
 *
 *
 * Example 1:
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 * Example 2:
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 * Example 3:
 * Input: nums = [], target = 0
 * Output: [-1,-1]
 *
 *
 * Constraints:
 *
 *
 * 0 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * nums is a non-decreasing array.
 * -10^9 <= target <= 10^9
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
   public:
    vector<int> searchRange(vector<int> &nums, int target) {
        if (nums.size() == 0) return {-1, -1};
        vector<int> res;
        res.push_back(getStart(nums, target));
        res.push_back(getEnd(nums, target));
        return res;
    }

   private:
    int getEnd(vector<int> &nums, int target) {
        int l = -1;
        int r = nums.size();
        while (l != r - 1) {
            int m = l + (r - l) / 2;
            if (nums[m] <= target) {
                l = m;
            } else {
                r = m;
            }
        }
        if (l >= nums.size() || nums[l] != target) {
            return -1;
        } else {
            return l;
        }
    }
    int getStart(vector<int> &nums, int target) {
        int l = -1;
        int r = nums.size();
        while (l != r - 1) {
            int m = l + (r - l) / 2;
            if (nums[m] >= target) {
                r = m;
            } else {
                l = m;
            }
        }
        if (r >= nums.size() || nums[r] != target) {
            return -1;
        } else {
            return r;
        }
    }
};
// @lc code=end

/*
 * @lc app=leetcode id=154 lang=cpp
 *
 * [154] Find Minimum in Rotated Sorted Array II
 *
 * https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/description/
 *
 * algorithms
 * Hard (41.88%)
 * Likes:    1350
 * Dislikes: 262
 * Total Accepted:    229.5K
 * Total Submissions: 547.5K
 * Testcase Example:  '[1,3,5]'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 *
 * (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
 *
 * Find the minimum element.
 *
 * The array may contain duplicates.
 *
 * Example 1:
 *
 *
 * Input: [1,3,5]
 * Output: 1
 *
 * Example 2:
 *
 *
 * Input: [2,2,2,0,1]
 * Output: 0
 *
 * Note:
 *
 *
 * This is a follow up problem to Find Minimum in Rotated Sorted Array.
 * Would allow duplicates affect the run-time complexity? How and why?
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
       int len = nums.size();
       int l = 0, r = len - 1;
       while(l < r) {
           int m = l + (r - l) / 2;
           if (nums[r] < nums[m]) {
               l = m + 1;
           } else if(nums[r] > nums[m]){
               r = m;
           } else {
               r -= 1;
           }
       }
       return nums[l];
    }
};
// @lc code=end


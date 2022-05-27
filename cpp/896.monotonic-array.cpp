/*
 * @lc app=leetcode id=896 lang=cpp
 *
 * [896] Monotonic Array
 *
 * https://leetcode.com/problems/monotonic-array/description/
 *
 * algorithms
 * Easy (57.97%)
 * Likes:    1160
 * Dislikes: 48
 * Total Accepted:    166.3K
 * Total Submissions: 286.9K
 * Testcase Example:  '[1,2,2,3]'
 *
 * An array is monotonic if it is either monotone increasing or monotone
 * decreasing.
 *
 * An array nums is monotone increasing if for all i <= j, nums[i] <= nums[j].
 * An array nums is monotone decreasing if for all i <= j, nums[i] >= nums[j].
 *
 * Given an integer array nums, return true if the given array is monotonic, or
 * false otherwise.
 *
 *
 * Example 1:
 * Input: nums = [1,2,2,3]
 * Output: true
 * Example 2:
 * Input: nums = [6,5,4,4]
 * Output: true
 * Example 3:
 * Input: nums = [1,3,2]
 * Output: false
 * Example 4:
 * Input: nums = [1,2,4,5]
 * Output: true
 * Example 5:
 * Input: nums = [1,1,1]
 * Output: true
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * -10^5 <= nums[i] <= 10^5
 *
 *
 */

// @lc code=start
class Solution {
   public:
    // bool isMonotonic(vector<int>& nums) {
        // if (nums.size() == 0 || nums.size() == 1) return true;

        // int s = 1;
        // while (s < nums.size() && nums[s - 1] == nums[s]) s++;

        // if (s == nums.size()) return true;

        // if (nums[s] > nums[s - 1]) {
            // for (; s < nums.size(); s++) {
                // if (nums[s] < nums[s - 1]) return false;
            // }

        // } else {
            // for (; s < nums.size(); s++) {
                // if (nums[s] > nums[s - 1]) return false;
            // }
        // }
        // return true;
    // }

    bool isMonotonic(vector<int>& A) {
        bool inc = true, dec = true;
        for (int i = 1; i < A.size(); ++i) {
            inc &= (A[i - 1] <= A[i]);
            dec &= (A[i - 1] >= A[i]);
            if (!inc && !dec) return false;
        }
        return true;
    }
};
// @lc code=end

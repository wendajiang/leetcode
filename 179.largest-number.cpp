/*
 * @lc app=leetcode id=179 lang=cpp
 *
 * [179] Largest Number
 *
 * https://leetcode.com/problems/largest-number/description/
 *
 * algorithms
 * Medium (31.71%)
 * Likes:    3725
 * Dislikes: 352
 * Total Accepted:    272K
 * Total Submissions: 857.7K
 * Testcase Example:  '[10,2]'
 *
 * Given a list of non-negative integers nums, arrange them such that they form
 * the largest number.
 *
 * Note: The result may be very large, so you need to return a string instead
 * of an integer.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [10,2]
 * Output: "210"
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [3,30,34,5,9]
 * Output: "9534330"
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [1]
 * Output: "1"
 *
 *
 * Example 4:
 *
 *
 * Input: nums = [10]
 * Output: "10"
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 100
 * 0 <= nums[i] <= 10^9
 *
 *
 */

// @lc code=start
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string ans;

        sort(nums.begin(), nums.end(), [](int a, int b) {
            return to_string(a) + to_string(b) > to_string(b) + to_string(a);
        });

        for (auto num : nums) {
            ans += to_string(num);
        }


        return ans[0] == '0' ? "0" : ans;

    }
};
// @lc code=end

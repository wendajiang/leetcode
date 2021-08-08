/*
 * @lc app=leetcode id=525 lang=cpp
 *
 * [525] Contiguous Array
 *
 * https://leetcode.com/problems/contiguous-array/description/
 *
 * algorithms
 * Medium (43.37%)
 * Likes:    3138
 * Dislikes: 151
 * Total Accepted:    197.2K
 * Total Submissions: 446.6K
 * Testcase Example:  '[0,1]'
 *
 * Given a binary array nums, return the maximum length of a contiguous
 * subarray with an equal number of 0 and 1.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [0,1]
 * Output: 2
 * Explanation: [0, 1] is the longest contiguous subarray with an equal number
 * of 0 and 1.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [0,1,0]
 * Output: 2
 * Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal
 * number of 0 and 1.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * nums[i] is either 0 or 1.
 *
 *
 */

// @lc code=start
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int cnt = 0;
        unordered_map<int, int> mp;
        int res = 0;
        mp[cnt] = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                cnt++;
            } else {
                cnt--;
            }
            if (mp.count(cnt)) {
                int pre = mp[cnt];
                res = max(res, i - pre);
            } else {
                mp[cnt] = i;
            }
        }
        return res;
    }
};
// @lc code=end

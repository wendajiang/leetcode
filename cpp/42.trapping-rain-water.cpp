/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 *
 * https://leetcode.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (50.60%)
 * Likes:    12784
 * Dislikes: 185
 * Total Accepted:    807.6K
 * Total Submissions: 1.5M
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * Given n non-negative integers representing an elevation map where the width
 * of each bar is 1, compute how much water it can trap after raining.
 *
 *
 * Example 1:
 *
 *
 * Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 * Explanation: The above elevation map (black section) is represented by array
 * [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue
 * section) are being trapped.
 *
 *
 * Example 2:
 *
 *
 * Input: height = [4,2,0,3,2,5]
 * Output: 9
 *
 *
 *
 * Constraints:
 *
 *
 * n == height.length
 * 0 <= n <= 3 * 10^4
 * 0 <= height[i] <= 10^5
 *
 *
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        int l = 0, r = height.size() - 1;

        int max_l = height[l];
        int max_r = height[r];
        int ans = 0;
        while(l < r) {
            if (max_l < max_r) {
                ans += max_l - height[l];
                max_l = max(max_l, height[++l]);
            } else {
                ans += max_r - height[r];
                max_r = max(max_r, height[--r]);
            }
        }
        return ans;
    }
};
// @lc code=end

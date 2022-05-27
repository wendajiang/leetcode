/*
 * @lc app=leetcode id=164 lang=cpp
 *
 * [164] Maximum Gap
 *
 * https://leetcode.com/problems/maximum-gap/description/
 *
 * algorithms
 * Hard (40.22%)
 * Likes:    1686
 * Dislikes: 254
 * Total Accepted:    125.3K
 * Total Submissions: 311.2K
 * Testcase Example:  '[3,6,9,1]'
 *
 * Given an integer array nums, return the maximum difference between two
 * successive elements in its sorted form. If the array contains less than two
 * elements, return 0.
 *
 * You must write an algorithm that runs in linear time and uses linear extra
 * space.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [3,6,9,1]
 * Output: 3
 * Explanation: The sorted form of the array is [1,3,6,9], either (3,6) or
 * (6,9) has the maximum difference 3.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [10]
 * Output: 0
 * Explanation: The array contains less than 2 elements, therefore return
 * 0.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * 0 <= nums[i] <= 10^9
 *
 *
 */

// @lc code=start
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        int mx = INT_MIN, mn = INT_MAX, n = nums.size(), pre = 0, ans = 0;
        for (auto num : nums) {
            mn = min(mn, num);
            mx = max(mx, num);
        }

        int size = (mx - mn) / n + 1;
        vector<int> bucket_min(n, INT_MAX), bucket_max(n, INT_MIN);
        for (int num : nums) {
            int idx = (num - mn) / size;
            bucket_min[idx] = min(bucket_min[idx], num);
            bucket_max[idx] = max(bucket_max[idx], num);
        }

        for (int i = 1; i < n; i++) {
            if (bucket_min[i] == INT_MAX || bucket_max[i] == INT_MIN) continue;
            ans = max(ans, bucket_min[i] - bucket_max[pre]);
            pre = i;
        }
        return ans;
    }
};
// @lc code=end
